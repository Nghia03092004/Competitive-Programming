#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll i = 2; i * i <= n; ++i)  {
            while (n % i == 0 && n != i) n /= i;
        }
        cout << n << '\n';
    }
}
