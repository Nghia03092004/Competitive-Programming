#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e6 + 5;
int n;
int a[N], dp[N][3];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    dp[1][1] = -a[1];
    dp[1][2] = 0;

    for (int i = 2; i <= n; ++i) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - a[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + a[i]);
    }

    cout << dp[n][2];
}