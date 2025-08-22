#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int maxN = 1e5 + 5;
int n, m;
int a[maxN], ans[maxN], dist[maxN];
vector<ii> g[maxN];
priority_queue<ii, vector<ii>, greater<ii>> q;

void dijk(int x) {
    while (!q.empty()) {
        int cost = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (cost > dist[u]) continue;
        for (auto v : g[u]) {
            if (dist[v.fi] > dist[u] + v.se) {
                dist[v.fi] = dist[u] + v.se;
                q.push({dist[v.fi], v.fi});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] == x)
            if (dist[i] == 1e18) ans[i] = -1;
            else ans[i] = dist[i];
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) {
            dist[i] = 0;
            q.push({dist[i], i});
        } else dist[i] = 1e18;
    }
    dijk(1);
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            dist[i] = 0;
            q.push({dist[i], i});
        } else dist[i] = 1e18;
    }
    dijk(0);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
}