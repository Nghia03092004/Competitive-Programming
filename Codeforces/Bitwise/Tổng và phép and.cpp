#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int mul(int a, int b) {
    return (a * b) % mod;
}

int fastpow(int a, int exp) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, a = mul(a, a))
        if (exp & 1) ans = mul(ans, a);
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    cout << fastpow(n, k);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        solve(); 
        cout  << '\n';
    }

}