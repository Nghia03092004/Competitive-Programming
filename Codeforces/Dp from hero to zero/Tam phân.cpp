#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int maxN = 1e5 + 5;
int dp[maxN][3];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
}