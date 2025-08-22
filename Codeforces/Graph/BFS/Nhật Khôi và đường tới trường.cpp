#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int maxN = 5e2 + 5;
int n, K;
char a[maxN][maxN];
int dist[maxN][maxN][5];
queue<iii> q;

int valid(int x) {
    return (x >= 1 && x <= n);
}

void BFS(ii start) {
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            for (int x = 0; x <= K; ++x)
                dist[i][j][x] = 1e9;
    dist[start.fi][start.se][0] = 0;
    q.push({0, {start.fi, start.se}});

    while (!q.empty()) {
        int u = q.front().se.fi;
        int v = q.front().se.se;
        int k = q.front().fi;
        q.pop();
        for (int s =  0; s < 4; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];

            if (valid(x) && valid(y)) {
                if (a[x][y] != '*') {
                    if (dist[x][y][k] > dist[u][v][k] + 1) {
                        dist[x][y][k] = dist[u][v][k] + 1;
                        q.push({k, {x, y}});
                    }
                } else {
                    x += dx[s];
                    y += dy[s];
                    if (a[x][y] != '*' && valid(x) && valid(y) 
                        && k + 1 <= K && dist[x][y][k + 1] > dist[u][v][k] + 1) 
                    {
                        dist[x][y][k + 1] = dist[u][v][k] + 1;
                        q.push({k + 1, {x, y}});
                    }
                }
            }
        }
    }
} 

void solve() {
    cin >> n >> K;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            cin >> a[i][j];


    BFS({1, 1});

    int ans = 1e9;
    for (int i = 0; i <= K; ++i) 
        ans = min(ans, dist[n][n][i]);

    cout << (ans == 1e9 ? -1 : ans);
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