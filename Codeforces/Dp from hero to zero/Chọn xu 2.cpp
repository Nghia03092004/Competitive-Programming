#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int maxS = 1e6 + 6;
int n, s;
int a[105], dp[maxS];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0] = 1;
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= s; ++i)
            if (i - a[j] >= 0)
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;

    cout << dp[s];
}