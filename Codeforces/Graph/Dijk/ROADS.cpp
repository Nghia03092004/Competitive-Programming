#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define iii pair<int, ii> 

const int maxN = 1e2 + 5;
const int maxK = 1e4 + 5;
int k, n, m;
vector<iii> g[maxN];
int dist[maxN][maxK];
priority_queue<iii, vector<iii>, greater<iii> > q;


void dijk(int start) {
    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j <= k; ++j) 
            dist[i][j] = 1e18;
    dist[start][0] = 0;
    q.push({dist[start][0], {start, 0}});
    while (!q.empty()) {
        int d = q.top().fi;
        int u = q.top().se.fi;
        int cost = q.top().se.se;
        q.pop();
        if (d > dist[u][cost]) continue;
        for (auto x: g[u]) {
            int v = x.fi;
            int w = x.se.fi;
            int c = x.se.se;
            if (c + cost <= k && dist[v][cost + c] > dist[u][cost] + w) {
                dist[v][cost + c] = dist[u][cost] + w;
                q.push({dist[v][cost + c], {v, cost + c}});
            }
        }
    } 
}

void solve() {
    cin >> k >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        g[u].push_back({v, {w, c}});
    }
    dijk(1);
    int ans = 1e18;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dist[n][i]);
    cout << (ans == 1e18 ? -1 : ans);
    for (int i = 1; i <= n; ++i) 
        g[i].clear();
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