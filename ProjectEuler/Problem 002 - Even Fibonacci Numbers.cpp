#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll a = 1, b = 2;
        ll ans = 0;
        while (b <= n) {
            if (b % 2 == 0)
                ans = ans + b;
            ll tmp = a + b;
            a = b;
            b = tmp;
        }
        cout << ans << '\n';
    }
}
