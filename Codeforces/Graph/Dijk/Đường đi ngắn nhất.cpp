#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxN = 1e5 + 5;
int n, m;
int dist[maxN], f[maxN], mini[maxN], maxi[maxN];
vector<ii> g[maxN];
priority_queue<ii, vector<ii>, greater<ii>> q;

void dijk(int start) {
    for (int i = 1; i <= n; ++i)
        dist[i] = 1e18;
    dist[start] = 0; f[start] = 1;
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
                f[v.fi] = f[u];
                mini[v.fi] = mini[u] + 1;
                maxi[v.fi] = maxi[u] + 1;
            } else if (dist[v.fi] == dist[u] + v.se) {
                f[v.fi] = (f[v.fi] + f[u]) % mod;
                mini[v.fi] = min(mini[v.fi], mini[u] + 1);
                maxi[v.fi] = max(maxi[v.fi], maxi[u] + 1);
            }
        }
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijk(1);
    if (dist[n] == 1e18) cout << -1;
    else cout << dist[n] << ' ' << f[n] << ' ' << mini[n] << ' ' << maxi[n];
}
 