#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e6 + 10;
int n, cnt = 0, q;
bool isPrime[maxN + 1];
int prime[maxN + 1];
int a[1005][1005], pref[1005][1005];

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

/* int findLeft(int x) { */
/*      int l = 1, r = cnt, ret = -1; */
/*      while (l <= r) { */
/*           int mid = l + r >> 1; */
/*           if (prime[mid] <= x) */ 
/*                l = mid + 1, ret = prime[mid]; */
/*           else */ 
/*                r = mid - 1; */
/*      } */
/*      return ret; */
/* } */

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

     cin >> n >> q;
     for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= n; ++j) {
               int x; cin >> x;
               a[i][j] += findRight(x) - x;
               /* int left = findLeft(x), right = findRight(x); */

               /* if (left == -1) a[i][j] += abs(x - right); */
               /* else if (right == -1) a[i][j] += abs(x - left); */
               /* else (abs(x - left) > abs(x - right) ? a[i][j] += abs(x - right) : a[i][j] += abs(x - left)); */

          }
     }

     for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= n; ++j) 
               pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
     
     while (q--) {
          int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
          cout << pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1] << '\n'; 
     }
     
     return 0;
}