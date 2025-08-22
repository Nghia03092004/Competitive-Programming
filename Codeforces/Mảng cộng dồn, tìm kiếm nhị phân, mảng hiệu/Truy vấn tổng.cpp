#include<bits/stdc++.h>

using namespace std;

#define int long long
int q;

int f(int x) {
     return (x + 1) * x / 2;
}

int bs(int k) {
     int l = 1, r = (int) 1e8, ret = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (f(mid) <= k) 
               ret = mid, l = mid + 1;
          else 
               r = mid - 1;
     }
     return ret;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     
     cin >> q;

     while (q--) {
          int x; cin >> x;
          cout << bs(x) << '\n';
     } 
}