#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 5e2 + 5;
int n, k;
int a[N], f[N];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int maxi = -1e18;
        for (int j = i; j >= max((int)1, i - k + 1); --j) {
            maxi = max(maxi, a[j]);
            f[i] = max(f[i], f[j - 1] + maxi * (i - j + 1));
        }
    }
    cout << f[n];
}