#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e2 + 5;
int n, m;
pair<int, int> start;
int dist[maxN][maxN];
char f[maxN][maxN];
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void BFS(pair<int, int> start) {
     for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dist[i][j] = 1e9;
     dist[start.first][start.second] = 0;
     q.push(start);
     while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int s = 0; s < 4; ++s) {
            int x = u + dx[s];
            int y = v + dy[s];
            if (x >= 1 && y >= 1 && x <= n && y <= m &&
                f[x][y] != '*' && dist[x][y] > dist[u][v] + 1) {
                    dist[x][y] = dist[u][v] + 1;
                    q.push({x, y});
                }
        }
     }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> f[i][j];
            if (f[i][j] == 'C')
                start = {i, j};
        }
    }

    BFS(start);

    cout << (dist[1][1] == 1e9 ? -1 : dist[1][1]);
}