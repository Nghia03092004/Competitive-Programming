#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second

const int maxN = 4e5 + 10;
int n, m;
int par[maxN];
iii e[maxN];

int acs(int u) {
    if (par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void join(int u, int v) {
    par[acs(u)] = acs(v);
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> e[m + i].fi;
        e[m + i].se.fi = n + 1;
        e[m + i].se.se = i;
    }
    for (int i = 1; i <= m; ++i) 
        cin >> e[i].se.fi >> e[i].se.se >> e[i].fi;
    for (int i = 1; i <= n + 1; ++i) 
        par[i] = i;
    sort(e + 1, e + m + n + 1);
    int ans = 0;
    for (int i = 1; i <= m + n; ++i) {
        int u = e[i].se.fi;
        int v = e[i].se.se;
        int w = e[i].fi;
        if (acs(u) != acs(v)) {
            ans += w;
            join(u, v);
        }
    }
    cout << ans;
}