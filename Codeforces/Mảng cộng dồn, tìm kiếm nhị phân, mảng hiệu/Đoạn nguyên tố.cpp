#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e6 + 10;
int n, cnt = 0, ans = INT_MAX, k;
bool isPrime[maxN];
int prime[maxN], a[maxN], pref[maxN];

void sieve() {
     for (int i = 1; i <= maxN; ++i)
          isPrime[i] = true;
 
     prime[1] = false;
     for (int i = 2; i * i <= maxN; ++i)
          if (isPrime[i]) 
               for (int j = i * i; j <= maxN; j += i) 
                    isPrime[j] = false;
     
     for (int i = 2; i <= maxN; ++i) 
          if (isPrime[i])
               prime[++cnt] = i;
}

int findLeft(int x) {
     int l = 1, r = cnt, ret = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (prime[mid] <= x) 
               l = mid + 1, ret = prime[mid];
          else 
               r = mid - 1;
     }
     return ret;
}

int findRight(int x) {
     int l = 1, r = cnt, ret = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (prime[mid] >= x)
               r = mid - 1, ret = prime[mid];
          else 
               l = mid + 1;
     }
     return ret;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     
     sieve();

     cin >> n >> k;
     for (int i = 1; i <= n; ++i) {
          int x; cin >> x;
          int left = findLeft(x), right = findRight(x);

          if (left == -1) a[i] += abs(x - right);
          else if (right == -1) a[i] += abs(x - left);
          else (abs(x - left) > abs(x - right) ? a[i] += abs(x - right) : a[i] += abs(x - left));

          pref[i] = pref[i - 1] + a[i];
     }

     for (int i = k; i <= n; ++i) {
          ans = min(ans, pref[i] - pref[i - k + 1 - 1]);
     }
     
     cout << ans << '\n';
}