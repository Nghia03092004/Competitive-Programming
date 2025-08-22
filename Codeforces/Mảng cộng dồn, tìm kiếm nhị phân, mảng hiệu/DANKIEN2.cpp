#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e6 + 5;
int n;
int a[maxN];
long long pref[maxN];

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n;
     for (int i = 1; i <= n; ++i) {
          cin >> a[i];
          pref[i] = pref[i - 1] + a[i];
     }
     
     for (int i = 1; i <= n; ++i) {
          cout << 1ll * i * a[i] - pref[i] + pref[n] - pref[i] - 1ll * (n - i) * a[i] << ' ';
     }
}

// i * a[i] - pref[i] + pref[n] - pref[i] - (n - i) * a[i];