#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define iii pair<int, pair<int,int>>
#define fi first
#define se second

int dx[] = {-1, 0, 1};
int dy[] = { 1, 1, 1};

const int maxN = 5e2 + 5;
int n, m;
int a[maxN][maxN], dist[maxN][maxN];
vector<iii> g[maxN];
priority_queue<iii, vector<iii>, greater<iii>> q;

bool valid(int idx, int bound) {
    return (idx >= 1 && idx <= bound);
}

void dijk() {
    while (!q.empty()) {
        int cost = q.top().fi;
        int u = q.top().se.fi;
        int v = q.top().se.se;
        q.pop();
        if (cost > dist[u][v]) continue;
        for (int s = 0; s < 3; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];
            if (valid(x, n) && valid(y, m) && dist[x][y] > dist[u][v] + a[x][y]) {
                dist[x][y] = dist[u][v] + a[x][y];
                q.push({dist[x][y], {x, y}});
            }
        }
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            dist[i][j] = 1e18;
        }

    for (int i = 1; i <= n; ++i) {
        dist[i][1] = a[i][1];
        q.push({dist[i][1], {i, 1}});
    }

    dijk();

    int ans = 1e18;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, dist[i][m]);

    cout << ans;
    return 0;
}