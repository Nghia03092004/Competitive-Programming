#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[maxN];

int n, a[maxN];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return a * b % mod;
}

int fastpow(int a, int exp) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, a = a * a % mod)
        if (exp & 1) ans = ans * a % mod;
    return ans;
}

int C(int n, int k) {
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

main()
{
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);


    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i)
        fact[i] = mul(fact[i - 1], i);

    cin >> n;
    int cnt = 1, ans = 1, start = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            start = i;
            break;
        }
    }
    if (!start) {
        cout << 0;
        return 0;
    }
    for (int i = start; i <= n; ++i) {
        if (a[i] == 1) {
            ans = mul(ans, cnt);
            cnt = 1;
        } else ++cnt;
    }
    cout << ans;
}