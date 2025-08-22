#pragma GCC optimize("O3")
#pragma GCC opitmize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = (int) 17;

int n, k, a[maxN];
int dp[maxN][1 << maxN];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) 
        dp[i][1 << i] = 1;

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> ones;
        for (int i = 0; i < n; ++i) 
            if ((mask >> i) & 1) 
                ones.push_back(i);
        for (int i: ones) 
            for (int j: ones) 
                if (i != j && abs(a[i] - a[j]) > k)
                    dp[i][mask] += dp[j][mask ^ (1 << i)];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += dp[i][(1 << n)- 1];

    cout << ans;
}