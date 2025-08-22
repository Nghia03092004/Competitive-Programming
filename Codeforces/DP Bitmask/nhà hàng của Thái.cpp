#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 19;
const int MASK = 1 << 18;

int n, m, k;
int a[N][N], val[N];
int dp[N][MASK];

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0);

     cin >> n >> m >> k;
     for (int i = 0; i < n; ++i) 
          cin >> val[i];

     for (int i = 0; i < k; ++i) {
          int x, y, z;
          cin >> x >> y >> z;
          a[x - 1][y - 1] += z;
     }

     memset(dp, -0x3f, sizeof dp);

     for (int i = 0; i < n; ++i) 
          dp[i][1 << i] = val[i];


     int ans = -0x3f;

     for (int mask = 0; mask < (1 << n); ++mask) {
          vector<int> ones;
          for (int j = 0; j < n; ++j) 
               if ((mask >> j) & 1) 
                    ones.push_back(j);

          for (auto last: ones) 
               for (auto prelast: ones) {
                    if (last != prelast) 
                         dp[last][mask] = max(dp[last][mask], dp[prelast][mask ^ (1 << last)] + val[last] + a[prelast][last]);


               if (ones.size() == m)
                    ans = max(ans, dp[last][mask]);
          }
     }

     cout << ans;
}