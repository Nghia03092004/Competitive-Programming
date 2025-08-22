#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int l = 1; l <= n; ++l) 
        for (int r = l; r <= n; ++r) 
            for (int i = 0; i <= r - l; ++i) 
                a[l + i] &= a[r - i];

    cout << *max_element(a + 1, a + n + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}