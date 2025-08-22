#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e5 + 5;
int n, q;
long long pref[maxN];

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n;
     pref[0] = 0ll;
     for (int i = 1; i <= n; ++i) {
          int x; cin >> x;
          pref[i] = pref[i - 1] + x;
     }

     cin >> q;
     while (q--) {
          int l, r; cin >> l >> r;
          cout << pref[r] - pref[l - 1] << '\n';
     }
}