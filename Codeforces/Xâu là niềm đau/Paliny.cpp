#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define pow abcd

const int base = 311;
const int mod = 1e9 + 7;
const int maxN = 1e5 + 5;

int n;
char f[maxN];
int pow[maxN], pref[maxN], suff[maxN];

int add(int a, int b) {
  return (a + b) % mod;
}

int mul(int a, int b) {
  return (a * b) % mod;
} 

int sub(int a, int b) {
  return ((a - b) % mod + mod) % mod;
}

int getP(int l, int r) {
  return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
}

int getS(int l, int r) {
  return sub(suff[l], mul(suff[r + 1], pow[r - l + 1]));
}

bool checkE(int k) {
  for (int i = k; i <= n; ++i) {
    int mid = k / 2;
    if (getP(i - k + 1, i - mid) == getS(i - mid + 1, i))
      return true;
  }
  return false;
}

bool checkO(int k) {
  for (int i = k; i <= n; ++i) {
    int mid = k / 2;
    if (getP(i - k + 1, i - mid - 1) == getS(i - mid + 1, i))
      return true;
  }
  return false;
}

main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) 
    cin >> f[i];

  pow[0] = 1;
  for (int i = 1; i <= n; ++i) 
    pow[i] = mul(pow[i - 1], base);

  for (int i = 1; i <= n; ++i) 
    pref[i] = add(mul(pref[i - 1], base), f[i]);

  for (int i = n; i >= 1; --i) 
    suff[i] = add(mul(suff[i + 1], base), f[i]);

  int l = 1, r = n, even = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (checkE(2 * mid)) {
      l = mid + 1;
      even = 2 * mid;
    } else r = mid - 1;
  }

  l = 1, r = n;
  int odd = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (checkO(2 * mid - 1)) {
      l = mid + 1;
      odd = 2 * mid - 1;
    } else r = mid - 1;
  }


  cout << max(odd, even);
}  