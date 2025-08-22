#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int> 
#define st first
#define nd second

const int maxN = (int) 1e6 + 5;
int n, k;
ii a[maxN];
int pref[maxN];

int bs(int pos, int x) {
     int l = pos, r = n, res = -1;
     while (l <= r) {
          int mid = l + r >> 1;
          if (a[mid].st <= x) 
               l = mid + 1, res = mid;
          else 
               r = mid - 1;
     }
     return res;
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> k;
     for (int i = 1; i <= n; ++i)
          cin >> a[i].st >> a[i].nd;
     
     sort(a + 1, a + n + 1);
     for (int i = 1; i <= n; ++i)
          pref[i] = pref[i - 1] + a[i].nd;

     int ans = 0;
     for (int i = 1; i <= n; ++i) {
          int tmp = bs(i, a[i].st + 2*k);
          if (ans != -1)
               ans = max(ans, pref[tmp] - pref[i - 1]);
     }
     cout << ans;
     return 0;
}