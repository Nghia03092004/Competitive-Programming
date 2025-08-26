#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define st first
#define nd second

const int maxN = (int) 1e6 + 5;
int n, q, ans[maxN];
ii a[maxN], b[maxN];
int res; 
bool flag[maxN];
int par[maxN];
int sz[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);

    if (x < y) swap(x, y);

    if (x != y) {
        res -= sz[x] * (sz[x] + 1) / 2;
        res -= sz[y] * (sz[y] + 1) / 2;
        sz[x] += sz[y];
        res += sz[x] * (sz[x] + 1) / 2;
        par[y] = x;   
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        sz[i] = 1;
        par[i] = i;
        a[i] = {x, i};
        flag[i] = false;
    }

    for (int i = 1; i <= q; ++i) {
        int x; cin >> x;
        b[i] = {x, i};
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + q + 1);

    int l = 1;
    for (int i = 1; i <= q; ++i) {
        while (a[l].st <= b[i].st && l <= n) {
            ++res;
            flag[a[l].nd] = true;
            if (flag[a[l].nd - 1]) 
                join(a[l].nd - 1, a[l].nd);
            if (flag[a[l].nd + 1])
                join(a[l].nd + 1, a[l].nd);
            ++l;
        }
        ans[b[i].nd] = res;
    }

    for (int i = 1; i <= q; ++i) 
        cout << ans[i] << '\n';
}