#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long 
 
int bit[35];
 
int max_bit(int x) {
    int ret = 0;
    while (x) {
        x /= 2;
        ++ret;
    }
    return ret;
}
 
 
int formula(int x) {
    return x * (x - 1) / 2;
}
 
void solve() {
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
 
    for (int i = 1; i <= n; ++i)
        bit[max_bit(a[i])]++;
 
    int ans = 0;
    for (int i = 1; i <= 35; ++i)
        ans += formula(bit[i]);
 
    cout << ans;
    for (int i = 1; i <= 35; ++i) bit[i] = 0;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t; cin >> t;
    while (t--) {
        solve(); 
        cout  << '\n';
    }
 
}