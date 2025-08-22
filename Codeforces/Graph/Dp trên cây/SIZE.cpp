#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;
int n, dp[maxN];
vector<int> g[maxN];

void dfs(int u, int par) {
     dp[u] = 1;
     for (auto v: g[u]) {
          if (v != par) {
               dfs(v, u);
               dp[u] += dp[v];
          }
     }
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     cin >> n;
     for (int i = 1; i < n; ++i) {
          int u, v; cin >> u >> v;
          g[u].push_back(v);
          g[v].push_back(u);
     }  
     dfs(1, -1);
     for (int i = 1; i <= n; ++i) 
          cout << dp[i] << '\n';   
}