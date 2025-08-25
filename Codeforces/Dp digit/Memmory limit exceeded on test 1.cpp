#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int mod = 1e9 + 7;
string L, R;
int dp[105][1005][2][2][2];

bool isPrime(int x) {
     if (x < 2) 
          return false;
     if (x == 2 || x == 3) 
          return true;
     if ((x % 2 == 0) || (x % 3 == 0)) 
          return false;
     for (int i = 5; i * i <= x; i += 6) 
          if ((x % i == 0) || (x % (i + 2) == 0))
               return false;
     return true;
} 

int f(string &num, int pos, int sum, int is_odd, int tight, int lead) {
     if (pos == 0) 
          return isPrime(sum - 500);

     if (dp[pos][sum][is_odd][tight][lead] != -1)
          return dp[pos][sum][is_odd][tight][lead];

     int limit = tight ? (num[num.size() - pos] - '0') : 9;

     int res = 0;
     for (int i = 0; i <= limit; ++i) {
          if (i == 0 && lead) {
               res += f(num, pos - 1, sum, is_odd ^ 1, 0, 1);
               continue;
          }

          res += f(num, pos - 1, sum + ((pos & 1) ? -i : i), is_odd ^ 1, tight & (i == limit), 0);
     }

     res %= mod;
     dp[pos][sum][is_odd][tight][lead] = res;

     return res;
}

int g(string &num) {
     int sum = 0, pos = num.size() % 2;
     for (char x: num) {
          if (pos & 1) 
               sum -= (x - '0');
          else
               sum += (x - '0');
          pos = (pos + 1) % 2;
     }
     return isPrime(sum);
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> L >> R;
     memset(dp, -1, sizeof dp);
     int ans_R = f(R, R.size(), 500, R.size() & 1, 1, 1);
     memset(dp, -1, sizeof dp);
     int ans_L = f(L, L.size(), 500, L.size() & 1, 1, 1);
     cout << (ans_R - ans_L + g(L) % mod + mod) % mod;

     return 0;
}