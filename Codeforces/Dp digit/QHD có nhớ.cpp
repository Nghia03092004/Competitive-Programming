#include<bits/stdc++.h>

using namespace std;

#define int long long 

int n, k, x, y, ans = 0;
unordered_map<int, unordered_map<int, int>> f;

int cost(int i, int j) {
     return (i * j + 2 * i + 3 * j) % k;
}

int backtracking(int i, int j) {
     if (f.count(i) && f[i].count(j)) 
          return f[i][j];
     int x = i >> 1, y = j;
     bool ok = 0;
     if (x >= 1 && y >= 1) {
          f[i][j] = max(f[i][j], backtracking(x, y) + cost(i, j));
          ok = 1;
     } 
     x = i, y = j >> 1;
     if (x >= 1 && y >= 1) {
          f[i][j] = max(f[i][j], backtracking(x, y) + cost(i, j));
          ok = 1;
     }
     if (!ok) 
          return f[i][j] = cost(i, j);
     return f[i][j];
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
    
     cin >> n >> k >> x >> y;
     cout << backtracking(x, y);
}