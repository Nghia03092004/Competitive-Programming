#include<bits/stdc++.h>

using namespace std;

int n, x;
long long ans = 0;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> x;
     for (int i = 1; i <= n; ++i) {
          int y; cin >> y;
          ans += abs(y - x);
     }

     cout << ans;
}