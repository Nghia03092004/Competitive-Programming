#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define iii pair<ii, int>
#define st first
#define nd second

int k, r, m, n;
ii pos[23];
iii house[103];
bool vis[103];

bool inside(int i, int j) {
     return sqrt(pow(pos[i].st - house[j].st.st, 2) + pow(pos[i].nd - house[j].st.nd, 2)) <= r;
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> k >> r;
     cin >> m; 
     for (int i = 0; i < m; ++i) 
          cin >> pos[i].st >> pos[i].nd;
     cin >> n;
     for (int i = 0; i < n; ++i)
          cin >> house[i].st.st >> house[i].st.nd >> house[i].nd;


     int ans = 0;
     for (int mask = 0; mask < (1 << m); ++mask) {
          if (__builtin_popcount(mask) == k) {
               memset(vis, false, sizeof vis);
               for (int i = 0; i < m; ++i) 
                    if ((mask >> i) & 1) 
                         for (int j = 0; j < n; ++j) 
                              if (inside(i, j))
                                   vis[j] = true;

               int sum = 0;
               for (int i = 0; i < n; ++i)
                    if (vis[i])
                         sum += house[i].nd ;
               ans = max(ans, sum);
          }
     }

     cout << ans;
     return 0;
}