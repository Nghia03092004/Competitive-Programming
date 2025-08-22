#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int maxN = 1e5 + 5;
int n, m;
int a[maxN], dist[maxN];
vector<ii> g[maxN];
priority_queue<ii, vector<ii>, greater<ii> > q;

void dijk() {
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
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dist[i] = a[i];
        q.push({a[i], i});
    }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        w *= 2;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijk();

    for (int i = 1; i <= n; ++i) cout << dist[i] << ' ';
}