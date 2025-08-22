#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5;
int n, mod = 1e9 + 7;
int a[N], b[N], c[N];

main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] <= b[i])
                ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        c[i] = ans;
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = (ans * (c[i] - (i - 1))) % mod;
    cout << ans;
}