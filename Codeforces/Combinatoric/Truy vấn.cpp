#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;

int fastpow(int a, int exp, int MOD) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, a = a * a % MOD)
        if (exp & 1) ans = ans * a % MOD;
    return ans;
}

main()
{
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int tmp = fastpow(b, c, mod - 1);
        int ans = fastpow(a, tmp, mod);
        cout << ans << '\n';
    }
}