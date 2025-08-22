#include<bits/stdc++.h>

using namespace  std;

#define ii pair<int, long double>
#define iii pair<int, ii>
#define fi first
#define se second

const long double inf = 1e18;
const int maxN = 1e5 + 5;
int n, m, k;
vector<pair<int, long double>> g[maxN];
long double dist[maxN][15];

struct cmp {
    bool operator () (iii a, iii b) {
        return a.se.se > b.se.se;
    }
};

void dijk(int start) {
    priority_queue<iii, vector<iii>, cmp> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            dist[i][j] = 1e18;
    dist[start][0] = 0;
    q.push({start, {0, 0}});
    while (!q.empty()) {
        int u = q.top().fi;
        int cnt = q.top().se.fi;
        long double d = q.top().se.se;
        q.pop();
        if (d > dist[u][cnt]) continue;
        for (auto x: g[u]) {
            int v = x.fi;
            long double  w = x.se;
            for (int i = cnt; i <= k; ++i) {
                double c = d + w / pow(2, i - cnt);
                if (dist[v][i] > c) {
                    dist[v][i] = c;
                    q.push({v, {i, dist[v][i]}});
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijk(1);
    cout << fixed << setprecision(2) << dist[n][k];
}