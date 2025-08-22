#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 3e7 + 5;
bool prime[maxN];
int n, cnt[maxN];

void sieve() {
   for (int i = 1; i <= maxN; ++i) 
      prime[i] = true;
   prime[1] = false;

   for (int i = 2; i * i <= maxN; ++i) 
      if (prime[i]) 
         for (int j = i * i; j <= maxN; j += i)
            prime[j] = false;
}

signed main() {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   sieve();
   
   cin >> n;
   for (int i = 2; i <= n; ++i) {
      if (prime[i]) ++cnt[i];
   }

   int ans = 0;
   for (int i = 2; i <= n - i; ++i) {
      if (cnt[i] && prime[n - i]) {
         // cout << i << ' ' << n - i << endl;
         ans += cnt[n - i];
      }
   }

   cout << ans;
} 