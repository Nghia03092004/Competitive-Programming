#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 2e6 + 5;
int n;
int cnt[maxN];

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         if (i * j > n) break;
         ++cnt[i * j];
      }
   }

   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         if (i * j > n) break;
         ans += cnt[n - i * j];
      }
   }

   cout << ans;
} 