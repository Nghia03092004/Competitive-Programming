#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 998244353;
int fact[maxN];
char a[maxN];
int q, n;

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
    return mul(fact[n], pow(mul(fact[n - k], fact[k]), mod - 2));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i) fact[i] = mul(fact[i - 1], i);

    cin >> q;
    while (q--) {
        cin >> n;
        int chot = 0, trong = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == '0') ++trong;
            if (a[i] == '1' && a[i - 1] == '1') {
                ++trong; chot++;
                a[i] = '0'; a[i - 1] = '0';
            }
        }
        cout << C(trong, chot) << '\n';
    }
    return 0;
}