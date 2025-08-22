#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

const int maxN = 1e3 + 5;
int n, x, y;
int a[maxN][maxN];
int dist[maxN][maxN];
ii start, goal;
queue<ii> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void build() {
    int h1 = 1, h2 = n, c1 = 1, c2 = n;
    int cnt = 0;
    while (h1 <= h2 && c1 <= c2) {
        for (int i = c1; i <= c2; ++i)
            a[h1][i] = ++cnt;
        ++h1;
        for (int i = h1; i <= h2; ++i)
            a[i][c2] = ++cnt;
        --c2;
        for (int i = c2; i >= c1; --i)
            a[h2][i] = ++cnt;
        --h2;
        for (int i = h2; i >= h1; --i)
            a[i][c1] = ++cnt;
        ++c1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == x) start = {i, j};
            if (a[i][j] == y) goal = {i, j};
        }
    }
}

void BFS(ii start) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = 1e9;
    dist[start.fi][start.se] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        for (int s = 0; s < 4; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];
            if (x >= 1 && y >= 1 && x <= n && y <= n
                && __gcd(a[x][y], a[u][v]) == 1 && dist[x][y] > dist[u][v] + 1)
            {
                dist[x][y] = dist[u][v] + 1;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        build();
        BFS(start);
        cout << (dist[goal.fi][goal.se] == 1e9 ? -1 : dist[goal.fi][goal.se]) << '\n';
    }
}