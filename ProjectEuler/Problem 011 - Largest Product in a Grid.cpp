#include<bits/stdc++.h>

using namespace std;

const int maxN = 20;
int a[maxN][maxN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int ans = 0;
  for (int x = 0; x < maxN; ++x) 
    for (int y = 0; y < maxN; ++y)
      cin >> a[x][y];

  for (int x = 0; x < maxN; ++x) 
    for (int y = 0; y < maxN; ++y) {
        if (x + 3 < maxN) {
          int tmp = a[x][y] * a[x + 1][y] * a[x + 2][y] * a[x + 3][y];
          ans = max(ans, tmp);
        }
        if (y + 3 < maxN) {
          int tmp = a[x][y] * a[x][y + 1] * a[x][y + 2] * a[x][y + 3];
          ans = max(ans, tmp);
        }
        if (x + 3 < maxN and y + 3 < maxN) {
          int tmp = a[x][y] * a[x + 1][y + 1] * a[x + 2][y + 2] * a[x + 3][y + 3];
          ans = max(ans, tmp);
        }
        if (x + 3 < maxN and y - 3 >= 0) {
          int tmp = a[x][y] * a[x + 1][y - 1] * a[x + 2][y - 2] * a[x + 3][y - 3];
          ans = max(ans, tmp);
        } 
    }
    cout << ans;
}