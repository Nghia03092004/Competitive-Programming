#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 5;
int n;
int a[N];
int ans = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int mini = 1e18;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, a[i] - mini);
        mini = min(mini, a[i]);
    }

    cout << ans;
    return 0;
}