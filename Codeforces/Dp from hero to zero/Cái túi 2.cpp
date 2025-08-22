#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e2 + 5;
const int M = 1e4 + 5;
int n, W;
int w[N], v[N], a[N];
int f[N][M];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> W;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i] >> a[i];

    f[0][0] = 0;
    for (int i = 1; i <= W; ++i)
        f[0][i] = -1e18;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= W; ++j)
            for (int k = 0; k <= min(a[i], j / w[i]); ++k)
                f[i][j] = max(f[i][j], f[i - 1][j - k * w[i]] + k * v[i]);

        int ans = -1e18;
        for (int j = 0; j <= W; ++j)
            ans = max(ans, f[n][j]);

        cout << ans;
}