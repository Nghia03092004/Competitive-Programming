#include<bits/stdc++.h>

#define int unsigned long long

using namespace std;
using ll = unsigned long long;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << ll(pow((1ll * n * (n + 1) / 2), 2) - (1ll * n * (n + 1) * (2ll * n + 1) / 6)) << '\n';
    }
}
