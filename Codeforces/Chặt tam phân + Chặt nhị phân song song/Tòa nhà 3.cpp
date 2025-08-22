#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int maxN = (int) 2e5 + 5;
int n, a, b, c;
int h[maxN];

int f(int x) {
    int suma = 0, sumb = 0;
    for (int i = 1; i <= n; ++i) 
        if (h[i] <= x) 
            suma += x - h[i];
    for (int i = 1; i <= n; ++i)
        if (h[i] >= x) 
            sumb += h[i] - x;

    if (c >= a + b)
        return suma * a + sumb * b;
    else {
        if (sumb >= suma) 
            return c * suma + (sumb - suma) * b;
        else 
            return c * sumb + (suma - sumb) * a;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    sort(h + 1, h + n + 1);

    int l = 0, r = (int) 1e9, ans = 0;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) 
            l = m1 + 1, ans = m1;
        else 
            r = m2 - 1, ans = m2;
    }
    cout << f(ans) << '\n';
}