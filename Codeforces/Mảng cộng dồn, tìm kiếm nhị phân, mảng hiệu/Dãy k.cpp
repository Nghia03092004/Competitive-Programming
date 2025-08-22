#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN =  (int) 1e6 + 5;
int n, k;
int a[maxN], pref[maxN];

int bs(int pos) {
      int l = 1, r = pos, ret = -1;
      while (l <= r) {
          int mid = l + r >> 1;
          if (pref[pos] - pref[mid - 1] <= k) 
               ret = mid, r = mid - 1;
          else 
               l = mid + 1;
      }
      return ret;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> k;
     for (int i = 1; i <= n; ++i) {
          cin >> a[i];
          pref[i] = pref[i - 1] + a[i];
     }

     int ans = 0;
     for (int i = 1; i <= n; ++i) {
          int pos = bs(i);
          if (pos == -1) continue;
          ans += i - pos + 1;
     }
     cout << ans;
}