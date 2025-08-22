#include<bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
 
const int N = 1e3 + 5;
int n , m;
int a[N][N];
int dist[N][N][8];
queue < iii > q;
int dx[] = {-1 , 0 , 1 , 0, 1, -1, 1, -1};
int dy[] = {0 , -1 , 0 , 1, -1, 1, 1, -1};
 
void BFS(ii start) {
    for (int i = 1; i <= n; ++i) 
        for  (int j = 1; j <= m; ++j)
            for (int k = 0; k < 8; ++k) 
                dist[i][j][k] = 1e9;
    for (int k = 0; k < 8; ++k) {
        dist[start.fi][start.se][k] = 0;
        q.push({k, {start.fi, start.se}});
    }

    while (!q.empty()) {
        int u = q.front().se.fi;
        int v = q.front().se.se;
        int k = q.front().fi;
        q.pop();

        for (int s = 0; s < 8; ++s) {
            if (k == s) continue;
            int x = u + dx[s] * a[u][v];
            int y = v + dy[s] * a[u][v];
            if (x >= 1 && x <= n && y >= 1 && y <= m
                && dist[x][y][s] > dist[u][v][k] + 1) 
            {
                dist[x][y][s] = dist[u][v][k] + 1;
                q.push({s, {x, y}});
            }
        }
    }
}
 
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
 
   cin >> m >> n;
   for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) 
         cin >> a[i][j];
   BFS({1, 1});
   int ans = 1e9;
   for (int i = 0; i < 8; ++i) 
      ans = min(ans, dist[n][m][i]);
   cout << (ans == 1e9 ? -1 : ans); 
}