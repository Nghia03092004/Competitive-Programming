#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e3, maxM = (int) 1e3;
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int n, m, x, y, u, v;
int dist[maxN][maxM];
queue<pair<int, int>> q;

void BFS(pair<int, int> start) {
     for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= m; ++j)
               dist[i][j] = (int) 1e9;
     dist[start.first][start.second] = 0;
     q.push(start);
     
     while (!q.empty()) {
          int u = q.front().first;
          int v = q.front().second;
          q.pop();
          for (int s = 0; s < 8; ++s) {
               int x = u + dx[s];
               int y = v + dy[s];
               if (x >= 1 and x <= n and y >= 1 and y <= m
                          and dist[x][y] > dist[u][v] + 1)
               {
                    dist[x][y] = dist[u][v] + 1;
                    q.push({x, y});
               }
          }
     }
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> m;
     cin >> x >> y >> u >> v;

     BFS({x, y});

     cout << (dist[u][v] == (int) 1e9 ? -1 : dist[u][v]);
}