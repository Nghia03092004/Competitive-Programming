#include<bits/stdc++.h>

using namespace std;

const int maxN = 22;
const int mod = (int) 1e9 + 7;

int n, a[maxN][maxN];
int dp[maxN][1 << maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; ++i) 
        if (a[0][i]) 
            dp[0][1 << i] = 1;

    vector<int> cnt[maxN];

    for (int mask = 0; mask < (1 << n); ++mask) {
        int ones = 0;
        for (int j = 0; j < n; ++j) 
            if (((mask >> j) & 1) == 1) 
                ++ones;
        cnt[ones].push_back(mask);
    }

    for (int i = 1; i < n; ++i) {
        for (int mask: cnt[i + 1]) {
            for (int j = 0; j < n; ++j) 
                if (mask & (1 << j) && a[i][j])
                    dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ (1 << j)]) % mod;
        }
    }

    cout << dp[n - 1][(1 << n) - 1];

    return 0;
}