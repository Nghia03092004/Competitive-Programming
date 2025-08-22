#include<bits/stdc++.h>
using namespace std;

char s[10005];

void solve() {
    int n, k; cin >> n >> k;
    long long ans = 0;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i + k < n; ++i) {
        long long tmp = 1;
        for (int j = 0; j < k; ++j) 
            tmp *= s[i + j] - '0';
        ans = max(ans, tmp);
    }
    cout << ans;
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
