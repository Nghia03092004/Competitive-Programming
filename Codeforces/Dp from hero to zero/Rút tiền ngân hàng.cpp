#include<bits/stdc++.h>

using namespace std;

const int M = 1e4 + 5;
const int N = 1e2 + 5;
const int inf = 1e9 + 7;
int n, m;
int a[N];
int f[M];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    f[0] = 0;
    for (int i = 1; i <= m; ++i) {
        f[i] = inf;
        for (int j = 1; j <= n; ++j)
            if (i - a[j] >= 0)
                f[i] = min(f[i], f[i - a[j]] + 1);
    }

    cout  << f[m];
}

// 98 = 50 + 20 + 20 + 5 + 1 + 1 + 1