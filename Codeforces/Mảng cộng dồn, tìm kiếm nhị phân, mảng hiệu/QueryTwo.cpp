#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e5 + 5;
int n, q;
int a[maxN];

int bs(int x) {
     int l = 1, r = n, ret = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (a[mid] <= x) 
               l = mid + 1, ret = mid;
          else 
               r = mid - 1;
     }
     return ret;
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n;
     for (int i = 1; i <= n; ++i) cin >> a[i];
     sort(a + 1, a + n + 1);

     cin >> q;
     while (q--) {
          int x; cin >> x;
          int ans = bs(x);
          (ans == -1) ? cout << -1 : cout << a[ans];
          cout << '\n';
     }
}