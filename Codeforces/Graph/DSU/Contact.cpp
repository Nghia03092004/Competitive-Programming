#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = (int) 1e9 + 7;
const int maxN = (int) 1e5 + 5;

int n, m;
int par[maxN];
int sz[maxN];
int scc;

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        --scc;
    }
}

int power(int a, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    scc = n;
    for (int i = 1; i <= n; ++i) par[i] = i;

    for (int i = 1; i <= m; ++i) {
        int p, q, l; cin >> p >> q >> l;
        for (int j = 0; j < l; ++j) 
            join(p + j, q + j);
    }
    cout << power(2, scc);
}