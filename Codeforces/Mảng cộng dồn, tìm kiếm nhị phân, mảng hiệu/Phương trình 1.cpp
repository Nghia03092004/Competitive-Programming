#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = (int) 1e5 + 5;
int n, p;
int a[maxN], pref[maxN];

int bs(int r) {
     int l = 0, y = r;
     while (l <= r) {
          int mid = l + r >> 1;
          if (pref[y] - pref[mid] == p) 
               return 1;
          else if (pref[y] - pref[mid] > p) 
               l = mid + 1;
          else 
               r = mid - 1;

     }
     return -1;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> p;
     for (int i = 1; i <= n; ++i) {
          cin >> a[i];
          pref[i] = pref[i - 1] + a[i];
     }

     int ans = 0;
     for (int i = 1; i <= n; ++i)
          if (bs(i) != -1) ++ans;

     cout << ans;
     return 0;
}