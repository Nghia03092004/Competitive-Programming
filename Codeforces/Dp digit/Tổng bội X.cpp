#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int mod = 1e9 + 7;

string L, R;
int X, dp[105][905][2];

int f(string &num, int pos, int sum, int tight) {
     if (pos == 0) {
          if (sum % X == 0) 
               return 1;
          return 0; 
     }

     if (dp[pos][sum][tight] != -1)
          return dp[pos][sum][tight];

     int limit = (tight == 1) ? (num[num.size() - pos] - '0') : 9;

     int res = 0;
     for (int i = 0; i <= limit; ++i) 
          res += f(num, pos - 1, ((sum - i) % X + X) % X, tight & (i == limit));

     res %= mod;
     dp[pos][sum][tight] = res;

     return res;
}

int g(string &num) {
     int sum = 0;
     for (char v: num) {
          sum += (v - '0');
     }

     return (sum % X == 0);
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0); 

     cin >> L >> R >> X;
     memset(dp, -1, sizeof dp);
     int ans_R = f(R, R.size(), 0, 1);
     memset(dp, -1, sizeof dp);
     int ans_L = f(L, L.size(), 0, 1);

     cout << ((ans_R - ans_L + g(L)) % mod + mod) % mod;
}