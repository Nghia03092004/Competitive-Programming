#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxN = (int) 1e6 + 5;
int n, R;
int a[maxN], pref[maxN];

bool check(int k) { 
     for (int i = 1; i <= n - k + 1; i += k) {
          if (pref[i + k - 1] - pref[i - 1] < R) 
               return false;
     }
     return true;
}

/* int bs() { */
/*      int l = 1, r = 1e6, ret = -1; */
/*      while (l <= r) { */
/*           int mid = l + r >> 1; */
/*           if (check(mid)) */ 
/*                ret = mid, l = mid + 1; */
/*           else */ 
/*                r = mid - 1; */
/*      } */
/*      return ret; */
/* } */

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     
     cin >> n >> R;
     for (int i = 1; i <= n; ++i)
          cin >> a[i], pref[i] = pref[i - 1] + a[i];

     int ans = (int) 1e9 + 7;
     for (int i = 1; i * i <= n; ++i) {
          if (n % i == 0) {
              if (check(i)) 
                   ans = min(ans, i);
              int j = n / i;
              if (j != i) 
                   if (check(j)) 
                        ans = min(ans, j);
         }
     }


     cout << ans;
     return 0;
}