#include<bits/stdc++.h>

using namespace std;

#define y1 flsjf

#define ii pair<int, int> 
#define st first
#define nd second

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int maxN = (int) 1505;
int n, m;
char a[maxN][maxN];
int par[maxN * maxN];
bool check[maxN][maxN];
queue<ii> q;
int dist[maxN][maxN];
vector<ii> g[maxN * maxN];
int x1, y1, x2, y2;
int day;

int getId(int x, int y) {
    return (x - 1) * m + y;
}

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) 
        par[y] = x;
}

void BFS() {
    for (int i = 1; i <= n; ++i) {
        fill_n(check[i], m + 1, false);
        fill_n(dist[i], m + 1, 0);
    }
    while (!q.empty()) {
        int u = q.front().st;
        int v = q.front().nd;
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int x = u + dx[dir];
            int y = v + dy[dir];

            if (x < 1 || x > n || y < 1 || y > m) continue;

            if (!check[x][y] && a[x][y] == 'X') {
                check[x][y] = true;
                q.push({x, y});
                dist[x][y] = dist[u][v] + 1;
                g[dist[x][y]].push_back({x, y});
             } 
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'L') {
                x1 = i;
                y1 = j;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'L' && !(i == x1 && j == y1)) {
                x2 = i;
                y2 = j;
            }
        }
    }
    for (int i = 1; i <= n * m; ++i) par[i] = i;

    day = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != 'X') {
                g[day].push_back({i, j});
                q.push({i, j});
            }
        }
    } 

    BFS();

    day = 0;
    while (acs(getId(x1, y1)) != acs(getId(x2, y2))) {
        for (ii tmp: g[day]) {
            int u = tmp.st;
            int v = tmp.nd;
            a[u][v] = '.';
            for (int dir = 0; dir < 4; ++dir) {
                int x = u + dx[dir];
                int y = v + dy[dir];

                if (x >= 1 && x <= n && y >= 1 && y <= m) {
                    if (a[x][y] != 'X') 
                        join(getId(x, y), getId(u, v));
                }
            }
        }
        ++day;
    }
    cout << day - 1;
    return 0;
}