#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, a[N], L[N], R[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0) L[i] = 0;
        else L[i] = L[i - 1] + 1;
    for (int i = n; i >= 1; --i)
        if (a[i] == 0) R[i] = 0;
        else R[i] = R[i + 1] + 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, L[i - 1] + R[i + 1]);
    cout << ans;
    return 0;
}