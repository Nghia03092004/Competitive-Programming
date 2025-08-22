#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, long long>
#define iii pair<int, ii>
#define fi first
#define se second

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

const int inf = 1e9;
int n, m;
vector<vector<int>> a;
vector<vector<int>> dist;
vector<vector<bool>> vis;
priority_queue<iii, vector<iii>, greater<iii>> q;

void dijk() {
    while (!q.empty()) {
        int u = q.top().se.fi, v = q.top().se.se;
        int cost = q.top().fi;
        q.pop();
        if (vis[u][v]) continue;
        vis[u][v] = true;
        for (int s = 0; s < 8; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];
            if (x >= 1 && x <= n && y >= 1 && y <= m &&
                a[x][y] != -1 && dist[x][y] > dist[u][v] + a[x][y]) 
            { 
                dist[x][y] = dist[u][v] + a[x][y];
                q.push({dist[x][y], {x, y}});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n >> m) {
        if (m == 0 && n == 0) return 0;
        a.assign(n + 10, vector<int> (m + 10));
        dist.assign(n + 10, vector<int> (m + 10, inf));
        vis.assign(n + 10, vector<bool> (m + 10, false));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                char x; cin >> x;
                if (x == '.') a[i][j] = 1;
                else if (x == '#') a[i][j] = 0;
                else a[i][j] = -1;
            }     
        for (int i = 1; i <= n; ++i) 
            if (a[i][1] != -1) {
                dist[i][1] = a[i][1];
                q.push({dist[i][1], {i, 1}});
            }
        for (int i = 2; i <= m; ++i) 
            if (a[n][i] != -1) {
                dist[n][i] = a[n][i];
                q.push({dist[n][i], {n, i}});
            }

        dijk();
        int ans = inf;
        for (int i = 1; i <= m; ++i) 
            if (vis[1][i]) ans = min(ans, dist[1][i]);
        for (int i = 2; i <= n; ++i)
            if (vis[i][m]) ans = min(ans, dist[i][m]);
        cout << (ans == inf ? -1 : ans) << '\n';
    }
}