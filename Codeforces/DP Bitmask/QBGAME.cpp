#include<bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;
const int maxN = 1e4 + 5;

int n, a[8][maxN];
int dp[maxN][(1 << 8) + 5];
vector<int> g;

bool check (int mask) {
    for (int i = 1; i < 8; ++i) 
        if (((mask >> i) & 1) && ((mask >> i - 1) & 1)) return false;
    return true;  
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    for (int mask = 0; mask < (1 << 8); ++mask) 
        if (check(mask))
            g.push_back(mask);

    for (int mask : g) {
        int sum = 0;
        for (int j = 0; j < 8; ++j) 
            if ((mask >> j) & 1) 
                sum += a[j][0];
        dp[0][mask] = sum;
    }

    for (int i = 1; i < 8; ++i) {
        for (int mask1 : g) {
            int sum = 0;
            for (int j = 0; j < 8; ++j) 
                if ((mask1 >> j) & 1) 
                    sum += a[j][i];
            for (int mask2: g) 
                if (!(mask1 & mask2)) {
                    dp[i][mask1] = max(dp[i][mask1], dp[i - 1][mask2] + sum);
                }
        }
    }

    int ans = -inf;
    for (int mask: g) 
        ans = max(ans, dp[n - 1][mask]);

    cout << ans;
}