#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int maxN = 5e2 + 5;
int n, m;
ii start;
int dist[maxN][maxN], a[maxN][maxN], b[maxN][maxN];
queue<ii> q;

bool BFS(ii start, int mid) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
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
            if (x >= 1 && y >= 1 && x <= n && y <= m &&
                abs(a[x][y] - a[u][v]) <= mid && dist[x][y] > dist[u][v] + 1)
            {
                dist[x][y] = dist[u][v] + 1;
                q.push({x, y});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (b[i][j] == 1 && dist[i][j] == 1e9)
                return false;
    return true;
}

void solve(ii start) {
    int ans = 0;
    int l = 0, r = 1e9, mid;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (BFS(start, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> b[i][j];
            if (b[i][j] == 1)
                start = {i, j};
        }

    solve(start);
    /*
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << dist[i][j] << ' ';
        cout << endl;
    } */

}