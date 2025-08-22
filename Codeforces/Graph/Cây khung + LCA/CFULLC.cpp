#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second

const int maxN = 1e6 + 5;
int n, m;
int par[maxN];
ii e[maxN];

int acs(int u) {
    return par[u] == u ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    par[acs(u)] = acs(v);
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> e[i].fi;
        e[i].se = i;
        par[i] = i;
    }
    sort(e + 1, e + n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (acs(e[1].se) != acs(e[i].se)) {
            join(e[1].se, e[i].se);
            ans += e[1].fi + e[i].fi;
        }
    }
    cout << ans;
} 