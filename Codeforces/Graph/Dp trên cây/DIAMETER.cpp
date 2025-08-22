#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;
int n, res;
int dp[maxN];
vector<int> g[maxN];

void DFS(int u, int par) {
     for (auto v: g[u]) {
          if (v != par) {
               DFS(v, u);
               res = max(res, dp[u] + dp[v] + 1);
               dp[u] = max(dp[u], dp[v] + 1);
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
     DFS(1, -1);

     cout << res;
}