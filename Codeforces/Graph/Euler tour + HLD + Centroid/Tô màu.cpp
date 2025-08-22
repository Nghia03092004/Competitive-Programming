#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
const int L = log2(maxN) + 2;
int n, root, q;
int sz[maxN], f[maxN], h[maxN], par[maxN], best[maxN];
int P[maxN][L];
vector<int> g[maxN], new_g[maxN];
bool is_centroid[maxN];

void DFS(int u, int par) {
     sz[u] = 1;
     for (auto v: g[u]) {
          if (v != par && !is_centroid[v]) {
               DFS(v, u);
               sz[u] += sz[v];
          }
     }
}

int find_centroid(int u, int tree_sz, int par) {
     for (auto v: g[u]) {
          if (v != par && !is_centroid[v] && sz[v] > tree_sz / 2) 
               return find_centroid(v, tree_sz, u);
     }
     return u;
}

void build_centroid(int u, int pre_centroid) {
     DFS(u, -1);
     int centroid = find_centroid(u, sz[u], -1);

     if (root == 0) 
          root = centroid;

     is_centroid[centroid] = true;
     if (pre_centroid != -1) {
          new_g[pre_centroid].push_back(centroid);
          par[centroid] = pre_centroid;
     }

     for (auto v: g[centroid]) 
          if (!is_centroid[v])
               build_centroid(v, centroid);
}

void DFS_2(int u) {
     for (auto v: new_g[u]) {
          DFS_2(v);
          f[u] = max(f[u], f[v] + 1);
     }
}

void DFS_1(int u, int par) {
     for (auto v: g[u]) 
          if (v != par) {
               h[v] = h[u] + 1;
               P[v][0] = u;
               DFS_1(v, u);
          }
}

void init() {
     for (int i = 1; (1 << i) <= n; ++i) 
          for (int j = 1; j <= n; ++j) 
               P[j][i] = P[P[j][i - 1]][i - 1];
}

int LCA(int x, int y) {
     if (h[x] < h[y]) 
          swap(x, y);

     int z = log2(h[x]);

     for (int i = z; i >= 0; --i) 
          if (h[x] - (1 << i) >= h[y])
               x = P[x][i];

     if (x == y) return x;

     for (int i = z; i >= 0; --i) 
          if (P[x][i] != P[y][i]) {
               x = P[x][i];
               y = P[y][i];
          }

     return P[x][0];
}

int dist(int x, int y) {
     return h[x] + h[y] - 2 * h[LCA(x, y)];
}

void paint(int u) {
     int cur = u;
     while (cur != 0) {
          best[cur] = min(best[cur], dist(u, cur));
          cur = par[cur];
     }
}

int query(int u) {
     int ans = 1e9;
     int cur = u;
     while (cur != 0) {
          ans = min(ans, best[cur] + dist(u, cur));
          cur = par[cur];
     }
     return ans;
}
 
signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> q;
     for (int i = 1; i <= n - 1; ++i) {
          int u, v; cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
     }

     for (int i = 1; i <= n; ++i) 
          best[i] = 1e9;

     DFS_1(1, -1);

     init();
     build_centroid(1, -1);
     paint(1);

     while (q--) {
          int type; cin >> type;
          if (type == 1) {
               int u; cin >> u;
               paint(u);
          } else {
               int u; cin >> u;
               cout << query(u) << '\n';
          }
     }
}