#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;

int q, x, k;

int f(int cycle) {
    return (x + 20 * cycle) * (k - cycle * 4);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> x >> k;
        int ans = 0;
        if (x % 2 == 1) {
            ans = max(ans, x * k);
            x += (x % 10);
            --k;
        }

        if (x % 10 == 0) 
            cout << max(ans, x * k) << '\n';
        else {
            for (int i = 0; i <= 3 && k >= 0; ++i) {
                int l = 0, r = k / 4, res = 0;
                while (l <= r) {
                    int m1 = l + (r - l) / 3;
                    int m2 = r - (r - l) / 3;
                    if (f(m1) > f(m2)) 
                        r = m2 - 1, res = m2;
                    else 
                        l = m1 + 1, res = m1;
                }

                ans = max(ans, f(res));
                --k;
                x += (x % 10);
            }
            cout << ans << '\n';
        }
    }
}