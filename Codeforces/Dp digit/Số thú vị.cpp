#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int mod = 1e9 + 7;
string L, R;
int dp[105][2][2][2];

int f(string &num, int pos, int is_even, int tight, int lead) {
     if (pos == 0) return 1;

     if (dp[pos][is_even][tight][lead] != -1) 
          return dp[pos][is_even][tight][lead];

     int limit = (tight == 1) ? (num[num.size() - pos] - '0') : 9;

     int res = 0;
     if (is_even)
          for (int i = 0; i <= limit; i += 2) 
               res += f(num, pos - 1, is_even ^ 1, tight & (i == limit), 0);
     else {
          if (lead) 
               res += f(num, pos - 1, is_even, 0, 1);
          for (int i = 1; i <= limit; i += 2) 
               res += f(num, pos - 1, is_even ^ 1, tight & (i == limit), 0);
     }

     res %= mod;
     dp[pos][is_even][tight][lead] = res;

     return res;
}

int g(string &num) {
     int pos = 1;
     for (char x: num) {
          if (pos) {
               if ((x - '0') % 2 == 0)
                    return 0;
          } else {
               if ((x - '0') % 2 == 1) 
                    return 0;
          }
          pos = (pos + 1) % 2;
     }

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