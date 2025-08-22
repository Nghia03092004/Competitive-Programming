#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll ans = 1;
        for (int i = 2; i <= n; ++i) 
            ans = lcm(ans, i);
        cout << ans << '\n';
    }
}
