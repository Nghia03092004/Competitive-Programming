#include<bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second

const int N = 5e2 + 5;
int n , m , K;
int a[N][N];
int dist[N][N][5];
queue < iii > q;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , -1 , 0 , 1};
 
void BFS(ii start) {
   for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= m; ++j) 
         for (int x = 0; x < 4; ++x)
            dist[i][j][x] = 1e9;
   dist[start.fi][start.se][2] = 1;
   q.push({2, {start.fi, start.se}});

   while (!q.empty()) {
      int k = q.front().fi;
      int u = q.front().se.fi;
      int v = q.front().se.se;
      q.pop();

      // go straight ahead
      int x = u + dx[k];
      int y = v + dy[k];
      if (x >= 1 && x <= n && y >= 1 && y <= m
            && a[x][y] == 0 && dist[x][y][k] > dist[u][v][k] + 1) 
      {
         dist[x][y][k] = dist[u][v][k] + 1;
         q.push({k, {x, y}});
      }

        // turn left
      int new_k = (k + 1) % 4;
      x = u + dx[new_k];
      y = v + dy[new_k];
      if (x >= 1 && x <= n && y >= 1 && y <= m
            && a[x][y] == 0 && dist[x][y][new_k] > dist[u][v][k] + 1) 
      {
         dist[x][y][new_k] = dist[u][v][k] + 1;
         q.push({new_k, {x, y}});
      }
   }   
}
 
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   cin >> n >> m;
   for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) 
         cin >> a[i][j];
   BFS({1, 1});
   int x, y; cin >> x >> y;
   int ans = 1e9;
   for (int i = 0; i < 4; ++i) 
      ans = min(ans, dist[x][y][i]);
   cout << (ans == 1e9 ? 0 : ans); 
}