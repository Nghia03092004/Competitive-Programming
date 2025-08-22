#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxN = (int) 1e5 + 5;
int n, p, q, r;
int a[maxN], pref[maxN];

int bs(int l, int x) {
     int tmp = l, r = n;
     while (l <= r) {
          int mid = l + r >> 1;
          if (pref[mid] - pref[tmp - 1] == x) 
               return mid;
          else if (pref[mid] - pref[tmp - 1] > x) 
               r = mid - 1;
          else 
               l = mid + 1;
     }
     return -1;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     
     cin >> n >> p >> q >> r;
     for (int i = 1; i <= n; ++i) 
          cin >> a[i], pref[i] = pref[i - 1] + a[i];

     int ans = 0;
     for (int x = 1; x <= n; ++x) {
          int y, z, w;
          y = bs(x, p);
          if (y != -1) {
               z = bs(y + 1, q);
               if (z != -1) {
                    w = bs(z + 1, r);
                    if (w != -1)
                         ++ans;
               }
          }
     } 

     cout << ans << '\n';
     return 0;
}