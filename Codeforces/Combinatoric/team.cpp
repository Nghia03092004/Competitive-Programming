#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[maxN];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int fastpow(int a, int exp) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, a = a * a % mod)
        if (exp & 1) ans = ans * a % mod;
    return ans;
}

int C(int n, int k) {
    return mul(fact[n], fastpow(mul(fact[n - k], fact[k]), mod - 2));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i)
        fact[i] = mul(fact[i - 1], i);

    int n, a, b, d;
    while (cin >> n >> a >> b >> d) {
        cout << mul(C(n, a), fastpow(C(b, d), a)) << '\n';
    }
}