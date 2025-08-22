#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 105;
int n, a[N][N], f[N][N];

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        f[1][i] = a[1][i];

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = f[i - 1][j] + a[i][j];
            if (j - 1 >= 1)
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + a[i][j]);
            if (j + 1 <= n)
                f[i][j] = min(f[i][j], f[i - 1][j + 1] + a[i][j]);
        }
    }

    int ans = 1e18;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, f[n][i]);

    cout << ans;
    return 0;
}