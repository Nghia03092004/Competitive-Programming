#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

#define int unsigned int

const int maxN = 1e7 + 5;
bool prime[maxN];
vector<int> a;
map<int, ll> sums;

void sieve() {
  for (int i = 1; i < maxN; ++i) 
    prime[i] = true;
  for (int i = 2; i * i < maxN; ++i) 
    if (prime[i])
      for (int j = i * i; j < maxN; j += i) 
          prime[j] = false;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();
  for (int i = 2; i < maxN; ++i) 
    if (prime[i]) a.push_back(i);

  ll sum = 0;
  for (ll p: a) {
    sum += p;
    sums[p] = sum;
  }

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    auto it = sums.upper_bound(x);
    it--;
    cout << it->second << '\n';
  }
}
