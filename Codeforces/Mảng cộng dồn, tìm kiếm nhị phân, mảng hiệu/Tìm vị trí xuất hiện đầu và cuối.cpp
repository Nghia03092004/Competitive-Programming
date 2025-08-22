#include<bits/stdc++.h>

using namespace std;

const int maxN = (int)1e6 + 5;
int n, q;
int a[maxN];

int leftBS(int x) {
     int l = 1, r = n, ret = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (a[mid] == x) 
               ret = mid, r = mid - 1;
          else if (a[mid] < x) 
               l = mid + 1;
          else 
               r = mid - 1;
     }
     return ret;
}

int rightBS(int x) {
     int l = 1, r = n, ret = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (a[mid] == x) 
               ret = mid, l = mid + 1;
          else if (a[mid] < x) 
               l = mid + 1;
          else 
               r = mid - 1;
     }
     return ret;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n;
     for (int i = 1; i <= n; ++i) cin >> a[i];
     
     cin >> q;
     while (q--) {
          int x; cin >> x;
          cout << leftBS(x) << ' ' << rightBS(x) << '\n';
     }

     return 0;
}