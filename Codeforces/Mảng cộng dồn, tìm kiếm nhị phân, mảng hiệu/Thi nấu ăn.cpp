#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e5 + 5;
int n, m;
int a[maxN], p[maxN], pref[maxN];

int bs(int x) {
     int l = 1, r = n, res = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (pref[mid] >= x)
               res = mid, r = mid - 1;
          else 
               l = mid + 1;
     }
     return res;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n;
     for (int i = 1; i <= n; ++i) 
          cin >> a[i], pref[i] = pref[i - 1] + a[i];
     cin >> m;
     for (int i = 1; i <= m; ++i) cin >> p[i];

     for (int i = 1; i <= m; ++i) 
          cout << bs(p[i]) << ' ';
     return 0;
}