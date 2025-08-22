#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 2e6 + 5;
const int mod = 1e9 + 7;
int fact[maxN];
int n, m, x;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int pow(int a, int exp) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, a = a * a % mod)
        if (exp & 1)
            ans = ans * a % mod;
    return ans;
}

int C(int n, int k) {
    return mul(fact[n], pow(mul(fact[k], fact[n - k]), mod - 2));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i)
        fact[i] = mul(fact[i - 1], i);

    cin >> n >> m >> x;
    cout << ((m - n*x) < 0 ? 0 : C(m - n * x + n - 1, n - 1));
}