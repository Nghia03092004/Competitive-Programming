#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = 20;
const int maxM = 9 * 9 * maxN;
bool vis[maxM], fval[maxM];
int dp[maxN][maxM];

int nextVal(int x) {
     int sumSquare = 0;
     while (x) {
          int d = x % 10;
          sumSquare += d * d;
          x /= 10;
     }
     return sumSquare;
}

bool dfs(int x) {
     if (vis[x]) 
          return fval[x];
     vis[x] = true;
     return fval[x] = dfs(nextVal(x));
}

int calcDP(string &num, int pos, int sum, int tight) {
     if (pos == 0) 
          return !fval[sum];
     
     if (!tight && dp[pos][sum] != -1) 
          return dp[pos][sum];

     int limit = tight ? (num[num.size() - pos] - '0') : 9;

     int res = 0;
     for (int i = 0; i <= limit; ++i) {
          res += calcDP(num, pos - 1, sum + i * i, tight & (i == limit));
     }

     if (!tight) 
          dp[pos][sum] = res;
     return res;
}

bool isUnhappy(string &num) {
     int sumSquare = 0;
     for (char c: num) 
          sumSquare += (c - '0') * (c - '0');
     return !fval[sumSquare];
}

signed main() {
     freopen("PEARL.INP", "r", stdin);
     freopen("PEARL.OUT", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     vis[1] = fval[1] = true;
     for (int i = 2; i < maxM; ++i) dfs(i);

     memset(dp, -1, sizeof dp);

     int t; cin >> t;
     while (t--) {
          string L, R; cin >> L >> R;
          int ans_R = calcDP(R, R.size(), 0, 1);
          int ans_L = calcDP(L, L.size(), 0, 1);
          cout << ans_R - ans_L + isUnhappy(L) << '\n';
     }

     return 0;
}