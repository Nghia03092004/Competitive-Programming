#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxN = 3e4 + 5;
int n, m;
int dist1[maxN], dist2[maxN];
int path1[maxN], path2[maxN];
vector<ii> g[maxN];

void dijk(int start, int dist[], int path[]) {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    for (int i = 1; i <= n; ++i)
        dist[i] = 1e18;
    dist[start] = 0; path[start] = 1;
    q.push({dist[start], start});
    while (!q.empty()) {
        int cost = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (cost > dist[u]) continue;
        for (auto v : g[u]) {
            if (dist[v.fi] > dist[u] + v.se) {
                dist[v.fi] = dist[u] + v.se;
                q.push({dist[v.fi], v.fi});
                path[v.fi] = path[u];
            } else if (dist[v.fi] == dist[u] + v.se)
                path[v.fi] = (path[v.fi] + path[u]) % mod;
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

    dijk(1, dist1, path1); dijk(n, dist2, path2);

    vector<int> ans;
    for (int i = 1; i <= n; ++i)
        if (!(dist1[i] + dist2[i] == dist1[n] && (path1[i] * path2[i]) % mod == path1[n]))
            ans.push_back(i);
    cout << ans.size() << '\n';
    for (auto v: ans) cout << v << '\n';

}