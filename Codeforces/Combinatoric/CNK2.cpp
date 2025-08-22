#include<bits/stdc++.h>

using namespace std;

int mod = 28082002;
int dp[5005][5005];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[0][0] = 1;
    for (int i = 1; i <= 5001; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= 5001; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << '\n';
    }
}