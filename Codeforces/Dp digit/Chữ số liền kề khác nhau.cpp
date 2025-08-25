#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int mod = 1e9 + 7;
string L, R;
int dp[105][11][2][2];

int f(string &num, int pos, int last, int tight, int lead) {
     if (pos == 0) return 1;

     if (dp[pos][last][tight][lead] != -1) 
          return dp[pos][last][tight][lead];

     int limit = (tight == 1) ? (num[num.size() - pos] - '0') : 9;

     int res = 0;
     for (int i = 0; i <= limit; ++i) {
          if (last == i) {
               if (i == 0 && lead == 1) 
                    res += f(num, pos - 1, 0, 0, 1);
               else 
                    continue;
          } else 
               res += f(num, pos - 1, i, tight & (i == limit), 0);
     }

     res %= mod;
     dp[pos][last][tight][lead] = res;

     return res;
}

int g(string &num) {
     for (int i = 0; i < num.size() - 1; ++i) 
          if (num[i] == num[i + 1]) return 0;

     return 1;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> L >> R;
     memset(dp, -1, sizeof dp);
     int ans_R = f(R, R.size(), 0, 1, 1);
     memset(dp, -1, sizeof dp);
     int ans_L = f(L, L.size(), 0, 1, 1);

     cout << ((ans_R - ans_L + g(L)) % mod + mod) % mod;
     
     return 0;
}