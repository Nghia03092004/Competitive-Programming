#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int maxN = (int) 2e5 + 5;
int n, a[maxN];
double b[maxN];

double f(double x) {
    for (int i = 1; i <= n; ++i) 
        b[i] = a[i] - x;

    double mini = 0;
    double maxi = 0;
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        mini = min(mini + b[i], b[i]);
        maxi = max(maxi + b[i], b[i]);
        ans = max({ans, abs(mini), maxi});
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    double l = -10000, r = 10000;
    for (int i = 1; i <= 100; ++i) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2))
            l = m1;
        else 
            r = m2;
    }
    cout << setprecision(6) << fixed << f(l);
}