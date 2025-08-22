#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int maxN = 1e4 + 5;
int n, m, k, s, t;
int dist1[maxN], dist2[maxN];
vector<ii> a[maxN], b[maxN];

void dijk(int start, int dist[], vector<ii> g[]) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int i = 1; i <= n; ++i)
        dist[i] = 1e18;
    dist[start] = 0;
    q.push({dist[start], start});
    while (!q.empty()) {
        int cost = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (cost > dist[u]) continue;
        for (auto v: g[u]) {
            if (dist[v.fi] > dist[u] + v.se) {
                dist[v.fi] = dist[u] + v.se;
                q.push({dist[v.fi], v.fi});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= n; ++i) {
        a[i].clear();
        b[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        b[v].push_back({u, w});
    }
    dijk(s, dist1, a); dijk(t, dist2, b);
    int ans = dist1[t];
    for (int i = 1; i <= k; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (dist1[u] != 1e18 && dist2[v] != 1e18)
            ans = min(ans, dist1[u] + dist2[v] + w);
        if (dist1[v] != 1e18 && dist2[u] != 1e18)
            ans = min(ans, dist1[v] + dist2[u] + w);
    }
    if (ans >= 1e18) cout << -1;
    else cout << ans;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}