#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int mod = 1e9 + 7;
const int maxN = 1e5 + 5;
int n, m;
int dist1[maxN], dist2[maxN];
int path1[maxN], path2[maxN];
int cnt1[maxN], cnt2[maxN];
vector<ii> g[maxN];

void dijk(int start, int dist[], int path[], int cnt[]) {
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
                path[v.fi] = path[u];
                cnt[v.fi] = 1;
                q.push({dist[v.fi], v.fi});
            } else if (dist[v.fi] == dist[u] + v.se) {
                path[v.fi] = (path[v.fi] + path[u]) % mod;
                cnt[v.fi]++;
            }
        }
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijk(1, dist1, path1, cnt1); dijk(n, dist2, path2, cnt2);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dist1[i] + dist2[i] == dist1[n] && cnt1[i] == 1 && (path1[i] * path2[i]) % mod == path1[n])
            ++ans;

    cout << ans;
}