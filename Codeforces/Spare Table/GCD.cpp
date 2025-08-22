#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int maxN = 5e5 + 5;
int n, k;
int a[maxN];
int f[25][maxN];
 
int get(int l, int r) {
    int k = log2(r - l + 1);
    return __gcd(f[k][l], f[k][r - (1 << k) + 1]);
}
 
main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], f[0][i] = a[i];
 
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            f[i][j] = __gcd(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
 
    int ans = -INT_MAX;
    for (int i = k; i <= n; ++i)
        ans = max(ans, get(i - k + 1, i));
 
    cout << ans;
}