#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[maxN];
int n, m, k;
int res = 0;
int a[maxN];

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

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = m; i <= n; ++i) {
        int l = 1, r = i - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[i] - a[mid] <= k) {
                r = mid - 1;
                ans = mid;
            } else l = mid + 1;
        }
        int sz = 0;
        if (ans !=  -1) sz = i - ans;
        if (sz >= m - 1)
            res = (res + C(sz, m - 1)) % mod;
    }
    cout << res;

    return 0;
}