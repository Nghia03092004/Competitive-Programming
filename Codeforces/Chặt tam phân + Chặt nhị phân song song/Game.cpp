#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 2e5 + 5;
int n, m, q;
int par[maxN], ans[maxN], l[maxN], r[maxN];
pair<int, int> edge[maxN];
vector<int> queries[maxN], pos[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y)
        par[x] = y;
}

bool ok(int  id) {
    int ac = 0;
    for (auto person: pos[id]) {
        if (ac == 0) 
            ac = acs(person);

        if (ac != acs(person)) 
            return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x].push_back(i);
    }
    for (int i = 1; i <= q; ++i) 
        cin >> edge[i].first >> edge[i].second;

    for (int i = 1; i <= m; ++i)
        l[i] = 0, r[i] = q, ans[i] = -1;

    while (true) {
        bool check = true;
        for (int i = 1; i <= m; ++i) {
            if (l[i] > r[i]) continue;

            check = false;
            queries[(l[i] + r[i]) / 2].push_back(i);
        }

        if (check) break;

        for (int i = 1; i <= n; ++i)
            par[i] = i;

        for (int ti = 0; ti <= q; ++ti) {
            if (ti > 0) {
                int u = edge[ti].first;
                int v = edge[ti].second;
                join(u, v);
            }

            for (auto id: queries[ti]) {
                if (ok(id)) 
                    r[id] = ti - 1, ans[id] = ti;
                else
                    l[id] = ti + 1;
            }
            queries[ti].clear();
        }
    }
    for (int i = 1; i <= m; ++i) 
        cout << ans[i] << '\n';
}