#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 5e5 + 5;
int n, q;
int par[maxN], cnt[maxN];

int acs(int u) {
     return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
     int x = acs(u);
     int y = acs(v);
     if (x != y) {
          par[x] = y;
          cnt[y] += cnt[x]; 
     }
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> q;
     
     for (int i = 1; i <= n; ++i) {
          par[i] = i;
          cnt[i] = 1;
    }

     while (q--) {
          char c; cin >> c;
          if (c == '+') {
               int u, v;
               cin >> u >> v;
               join(u, v);
          } else {
               int u; cin >> u;
               cout << cnt[acs(u)] << '\n';
          }
     }
}