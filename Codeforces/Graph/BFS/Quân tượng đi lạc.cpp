#include<bits/stdc++.h>

using namespace std;

int dx[] = {-2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2};

int x, y, u, v;
int dist[9][9];
queue<pair<int, int>> q;

void BFS(pair<int, int> start) {
     for (int i = 1; i <= 8; ++i)
          for (int j = 1; j <= 8; ++j)
               dist[i][j] = (int) 1e9;
     dist[start.first][start.second] = 0;
     q.push(start);

     while (!q.empty()) {
          int u = q.front().first;
          int v = q.front().second;
          q.pop();
          for (int s = 0; s < 4; ++s) {
               int x = u + dx[s];
               int y = v + dy[s];
               if (x >= 1 and x <= 8 and y >= 1 and y <= 8
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

     cin >> x >> y >> u >> v;

     BFS({x, y});

     cout << (dist[u][v] == (int) 1e9 ? -1 : dist[u][v]);
}