#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int inf = 1e18;
const int N = 17;
int n, a[N][N];
int dp[N][1 << N];

main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> a[i][j];

    for (int mask = 0; mask < (1 << n); ++mask)
        for (int i = 0; i < n; ++i) 
            dp[i][mask] = inf;

    for (int i = 0; i < n; ++i) 
        dp[i][1 << i] = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> ones;
        for (int j = 0; j < n; ++j) 
            if (((mask >> j) & 1) == 1)
                ones.push_back(j);
        for (auto i: ones) 
            for (auto j: ones) 
                if (i != j) 
                    dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + a[j][i]);
    }

    int ans = inf;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }

    cout << ans;
}