#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int maxN = 2e3 + 5;
int n, m, w;
int a[maxN][maxN];
int dist1[maxN][maxN], dist2[maxN][maxN];

bool valid(int idx, int bound) {
    return (idx >= 1 && idx <= bound);
}

void bfs(ii start, int dist[][maxN]) {
    queue<ii> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dist[i][j] = 1e18;
    dist[start.fi][start.se] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        for (int s = 0; s < 4; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];
            if (valid(x, n) && valid(y, m) && a[x][y] != -1
                && dist[x][y] > dist[u][v] + w)
            {
                dist[x][y] = dist[u][v] + w;
                q.push({x, y});
            }
        }
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    bfs({1, 1}, dist1); bfs({n, m}, dist2);

    int u = 1e18, v = 1e18;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                u = min(u, dist1[i][j] + a[i][j]);
                v = min(v, dist2[i][j] + a[i][j]);
            }
        }
    }

    cout << (min(dist1[n][m], u + v) == 1e18 ? -1 : min(dist1[n][m], u + v));
}