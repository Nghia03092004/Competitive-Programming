#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 17;
const int MASK = (1 << 16);
int n, a[N][N];
int f[MASK], dp[MASK];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> a[i][j];

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> ones;
        for (int j = 0; j < n; ++j) 
            if ((mask >> j) & 1)
                ones.push_back(j);

        for (int i = 0; i < ones.size(); ++i) 
            for (int j = i + 1; j < ones.size(); ++j)
                f[mask] += a[ones[i]][ones[j]];
    }

    for (int mask = 0; mask < (1 << n); ++mask) 
        for (int submask = mask; submask; submask = (submask - 1) & mask)
            if ((mask & submask) == submask) 
                dp[mask] = max(dp[mask], dp[mask ^ submask] + f[submask]);

    cout << dp[(1 << n) - 1];
    // O (4^n)
}