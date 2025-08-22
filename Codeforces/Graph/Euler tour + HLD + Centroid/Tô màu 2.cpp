#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
int n, root, q;
int sz[maxN], f[maxN], h[maxN], par[maxN], a[maxN];
multiset<int> best[maxN];
vector<int> g[maxN], new_g[maxN];
bool is_centroid[maxN];
vector<pair<int, int>> acs[maxN];

void DFS(int u, int par) {
     sz[u] = 1;
     for (auto v: g[u]) 
          if (v != par && !is_centroid[v]) {
               DFS(v, u);
               sz[u] += sz[v];
          }
}

int find_centroid(int u, int tree_sz, int par) {
     for (auto v: g[u]) {
          if (v != par && !is_centroid[v] && sz[v] > tree_sz / 2)
               return find_centroid(v, tree_sz, u);
     }
     return u;
}

void get_dist(int u, int par, int centroid, int h) {
     for (auto v: g[u]) 
          if (v != par && !is_centroid[v])
               get_dist(v, u, centroid, h + 1);
     acs[u].push_back({centroid, h});
}

void build_centroid(int u, int pre_centroid) {
     DFS(u, -1);
     int centroid = find_centroid(u, sz[u], -1);

     for (auto v: g[centroid]) 
          if (!is_centroid[v])
               get_dist(v, centroid, centroid, 1);

     is_centroid[centroid] = true;

     for (auto v: g[centroid])
          if (!is_centroid[v])
               build_centroid(v, centroid);
}

void paint(int u) {
     best[u].insert(0);
     for (auto v: acs[u]) 
          best[v.first].insert(v.second);
}

void unpaint(int u) {
     best[u].erase(best[u].find(0));
     for (auto v: acs[u]) 
          best[v.first].erase(best[v.first].find(v.second));
}

int query(int u) {
     int ans = 1e9;
     if (!best[u].empty())
          ans = *best[u].begin();

     for (auto v: acs[u])
          if (!best[v.first].empty())
               ans = min(ans, *best[v.first].begin() + v.second);

     return ans;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     cin >> n >> q;
     for (int i = 1; i <= n - 1; ++i) {
          int u, v; cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
     }

     build_centroid(1, -1);

     while (q--) {
          int type; cin >> type;
          if (type == 1) {
               int u; cin >> u;
               a[u] ^= 1;
               if (a[u] == 1) 
                    paint(u);
               else 
                    unpaint(u);
          } else {
               int u; cin >> u;
               int ans = query(u);
               if (ans == 1e9) 
                    cout << "-1\n";
               else 
                    cout << ans << '\n';
          }
     }
 }