#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 21;
const int MASK = (1 << 20);
int n, start;
int dist[MASK];
queue<int> q;

void BFS(int start) {
     for (int i = 0; i < (1 << n); ++i) 
          dist[i] = inf;
     dist[start] = 0;
     q.push(start);

     while (!q.empty()) {
          int u = q.front();
          q.pop();
          if (u == 0 || u == (1 << n) - 1) {
               cout << dist[u];
               exit(0);
          }
          for (int i  = 0; i < n; ++i) {
               int tmp = u;
               if (i + 1 < n) {
                    tmp ^= (1 << i);
                    tmp ^= (1 << (i + 1));
                    if (dist[tmp] > dist[u] + 1) {
                         dist[tmp] = dist[u] + 1;
                         q.push(tmp);
                    }
               }
               if (i + 2 < n) {
                    tmp ^= (1 << (i + 2));
                    if (dist[tmp] > dist[u] + 1) {
                         dist[tmp] = dist[u] + 1;
                         q.push(tmp);
                    }
               }
          }
     }
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n;
     for (int i = 1; i <= n; ++i) {
          char x; cin >> x;
          start += (x - 'A') * (1 << (n - i));
     }
     BFS(start);
}s