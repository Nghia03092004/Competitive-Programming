#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int maxN = (int) 1e5 + 5;
int n, a, b, q;

int get(int l, int r) {
    return r * (r + 1) / 2 - (l - 1) * l / 2;
}

int f(int x) {
    return get(b - x + 1, b) + (n - x) * a;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> a >> b;
        int l = 0, r = min(b, n), ans = 0;
        while (l <= r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (f(m1) > f(m2)) 
                r = m2 - 1, ans = m2;
            else 
                l = m1 + 1, ans = m1;
        }
        cout << f(ans) << '\n';
    }
}