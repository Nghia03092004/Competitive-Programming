#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[maxN];

int n, a[maxN];
int cnt[256];

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

    string s;
    cin >> s;
    int n = s.size(), ans = 1;
    for (int i = 0 ; i < n; ++i)
        cnt[s[i]]++;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] != 0) {
            ans = mul(ans, C(n, cnt[i]));
            n -= cnt[i];
        }
    }
    cout << ans;
}