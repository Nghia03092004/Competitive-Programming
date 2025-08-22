#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int maxN = 1e3 + 5;
int n, m, k, cnt = 0;
int a[maxN][maxN];
bool vis[maxN][maxN];
queue<ii> q;
ii start;

void BFS(ii start) {
    vis[start.fi][start.se] = true;
    q.push(start);
    --cnt;
    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        for (int s = 0; s < 4; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];
            if (x >= 1 && y >= 1 && x <= n && y <= m &&
                a[x][y] == 1 && !vis[x][y])
            {
                vis[x][y] = true;
                q.push({x, y});
                --cnt;
            }
            if (cnt == 0) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i )
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) ++cnt, start.fi = i, start.se = j;
        }

    cnt -= k;

    BFS(start);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 1 && !vis[i][j]) cout << i << ' ' << j << '\n';
}