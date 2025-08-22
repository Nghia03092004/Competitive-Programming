#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
int n, m;
int a[maxN], b[maxN];

int f(int x) {
    int res = 0;
    for (int i = 1; i <= n; ++i) 
        if (a[i] < x) 
            res += x - a[i];

    for (int i = 1; i <= m; ++i) 
        if (b[i] > x)
            res += b[i] - x;
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    for (int i = 1; i <= m; ++i) 
        cin >> b[i]; 

    int l = 1, r = (int) 1e9, ans = 0;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) 
            l = m1 + 1, ans = m1;
        else 
            r = m2 - 1, ans = m2;
    }

    cout << f(ans);
 }