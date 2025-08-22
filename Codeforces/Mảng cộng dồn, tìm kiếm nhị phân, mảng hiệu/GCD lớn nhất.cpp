#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;
int n, k;
int a[maxN], pref[maxN], suff[maxN];

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> k;
     for (int i = 1; i <= n; ++i) cin >> a[i];
     pref[1] = a[1], suff[n] = a[n];
     for (int i = 2; i <= n; ++i) 
          pref[i] = __gcd(pref[i - 1], a[i]);
     for (int i = n - 1; i >= 1; --i) 
          suff[i] = __gcd(suff[i + 1], a[i]);

     int ans = 0;
     for (int i = 0; i <= n - k; ++i) 
          ans = max(ans, __gcd(pref[i], suff[i + k + 1])); 
     cout << ans;
}