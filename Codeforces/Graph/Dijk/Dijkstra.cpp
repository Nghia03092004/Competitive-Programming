#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>

const int maxN = 1e5 + 5;
int n, m;
int dist[maxN];
vector<ii> g[maxN];
priority_queue<ii, vector<ii>, greater<ii> > q;

void dijk(int start) {
    for (int i = 1; i <= n; ++i) dist[i] = 1e18;
    dist[start] = 0;
    q.push({dist[start], start});
    while (!q.empty()) {
        int cost = q.top().first;
        int u = q.top().second;
        q.pop();
        if (cost > dist[u]) continue;
        for (auto v: g[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                q.push({dist[v.first], v.first});
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
        g[v].push_back({u, w});
    }

    dijk(1);
    cout << (dist[n] == 1e18 ? -1 : dist[n]);
}