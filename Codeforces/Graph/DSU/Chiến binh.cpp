#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 3e6 + 5;
int n, m;
int a[maxN];
int par[maxN]; 

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);

    if (x < y) swap(x, y);

    if (x != y) par[y] = x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n + 1; ++i) 
        par[i] = i;
    for (int i = 1; i <= m; ++i ) {
        int l, r, x; cin >> l >> r >> x;
        while (l <= r) {
            l = acs(l);
            if (l > r) break;
            if (l != x) {
                a[l] = x;
                join(l, l + 1);
            }
            else ++l;
        }
    }

    for (int i = 1; i <= n; ++i) 
        cout << a[i] << ' ';

    return 0;
}