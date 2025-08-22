#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int maxN = 1e5 + 5;
int n, m, k;
int dist1[maxN], dist2[maxN];
vector<ii> g[maxN];
priority_queue<ii, vector<ii>, greater<ii>> q;

void dijk(int start, int dist[]) {
    for (int i = 1; i <= n; ++i) dist[i] = 1e18;
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

main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijk(1, dist1); dijk(n, dist2);

    while (k--) {
        int a, b;
        cin >> a >> b;
        int ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            if (dist1[i] != 1e18 && dist2[i] != 1e18) {
                ans = min(ans, dist1[i] * a + dist2[i] * b);
            }
        }
        cout << ans << '\n';
    }
}