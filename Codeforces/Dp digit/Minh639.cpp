#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int mod = 1e9 + 7;
string L, R;
int dp[105][35][35][35];

int f(string &num, int pos, int cnt3, int cnt6, int cnt9, int tight) {
     if (cnt3 < 0 || cnt6 < 0 || cnt9 < 0) 
          return 0;

     if (pos == 0) {
          if (cnt3 == 33 || cnt6 == 33 || cnt9 == 33) 
               return 0;
          return cnt3 == cnt6 && cnt6 == cnt9;
     }

     if (tight == 0 && dp[pos][cnt3][cnt6][cnt9] != -1)
          return dp[pos][cnt3][cnt6][cnt9];

     int limit = tight ? (num[num.size() - pos] - '0') : 9;

     int res = 0;
     for (int i = 0; i <= limit; ++i) {
          if (i == 3) {
               res += f(num, pos - 1, cnt3 - 1, cnt6, cnt9, tight & (i == limit));
               continue;
          } 
          if (i == 6) {
               res += f(num, pos - 1, cnt3, cnt6 - 1, cnt9, tight & (i == limit));
               continue;
          }
          if (i == 9) {
               res += f(num, pos - 1, cnt3, cnt6, cnt9 - 1, tight & (i == limit));
               continue;
          }
          res += f(num, pos - 1, cnt3, cnt6, cnt9, tight & (i == limit));
     }

     res %= mod;
     if (tight == 0)
          return dp[pos][cnt3][cnt6][cnt9] = res;

     return res;
}

int g(string &num) {
     int cnt3 = 0, cnt6 = 0, cnt9 = 0;
     for (char &c: num) {
          if (c - '0' == 3) ++cnt3;
          if (c - '0' == 6) ++cnt6;
          if (c - '0' == 9) ++cnt9;
     }
     return (cnt3 >= 1 && cnt3 == cnt6 && cnt6 == cnt9);
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     int q; cin >> q;
     memset(dp, -1, sizeof dp);
     while (q--) {
          cin >> L >> R;
          int ans_R = f(R, R.size(), 33, 33, 33, 1);
          int ans_L = f(L, L.size(), 33, 33, 33, 1);
          cout << ((ans_R - ans_L + g(L)) % mod + mod) % mod << '\n';
     }
}