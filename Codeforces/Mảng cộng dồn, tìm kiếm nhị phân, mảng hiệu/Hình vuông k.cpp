#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e3 + 5;
int n, R;
int a[maxN][maxN], pref[maxN][maxN];

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> R;
     for (int i = 1; i <= n; ++i) 
          for (int j = 1; j <= n; ++j) 
               cin >> a[i][j];

     for (int i = 1; i <= n; ++i) 
          for (int j = 1; j <= n; ++j) 
               pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];

     for (int k = n; k >= 1; --k)
          for (int i = 1; i <= n - k + 1; ++i) 
               for (int j = 1; j <= n - k + 1; ++j) 
                    if (pref[i + k - 1][j + k - 1] - pref[i + k - 1][j - 1] - pref[i - 1][j + k - 1] + pref[i - 1][j - 1] <= R) {
                         cout << k;
                         return 0;
                    }
}