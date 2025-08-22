#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
int n, m;
int x, y, u, v;
int a, b, c, d;
int e, f, g, h;
int ans;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int sub(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

int get(int n) {
    return ((n * (n + 1) % mod) / 2) % mod;
}

int calc(int x, int y, int u, int v) {
    int a = ((x + u)*(u - x + 1) / 2) % mod;
    int b = ((y + v)*(v - y + 1) / 2) % mod;
    return mul(a, b);
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> x >> y >> u >> v;
    cin >> a >> b >> c >> d;
    e = max(x, a);
    f = max(y, b);
    g = min(u, c);
    h = min(v, d);
    int sum = calc(1, 1, n, m);
    int sum1 = calc(x, y, u, v);
    int sum2 = calc(a, b, c, d);
    int sum3 = calc(e, f, g, h);
    ans = sub(sum, add(sum1, sum2));
    if (e <= g && f <= h)
        ans = add(ans, sum3);
    cout << ans;
}