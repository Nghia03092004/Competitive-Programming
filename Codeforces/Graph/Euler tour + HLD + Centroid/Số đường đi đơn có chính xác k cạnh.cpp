#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
int n, k, ans, mx_h;
int sz[maxN], dp[maxN];
vector<int> g[maxN];
bool is_centroid[maxN];

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

void get_dist(int u, int par, int h) {
     if (h <= k) ans += dp[k - h];

     for (auto v: g[u]) 
          if (v != par && !is_centroid[v])
               get_dist(v, u, h + 1);
}

void update(int u, int par, int h) {
     if (h <= k) 
          dp[h]++, mx_h = max(mx_h, h);

     for (auto v: g[u]) 
          if (v != par && !is_centroid[v]) 
               update(v, u, h + 1);
}

void build_centroid(int u, int pre_centroid) {
     DFS(u, -1);
     int centroid = find_centroid(u, sz[u], -1);

     dp[0] = 1;
     mx_h = 0;
     for (auto v: g[centroid]) 
          if (!is_centroid[v]) {
               get_dist(v, centroid, 1);
               update(v, centroid, 1);
          }

     for (int i = 0; i <= mx_h; ++i) dp[i] = 0;

     is_centroid[centroid] = true;

     for (auto v: g[centroid])
          if (!is_centroid[v])
               build_centroid(v, centroid);
}


signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     cin >> n >> k;
     for (int i = 1; i <= n - 1; ++i) {
          int u, v; cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
     }

     build_centroid(1, -1);

     cout << ans;
 }