#include<bits/stdc++.h>

using namespace std;

const int maxN = 3e3 + 5;
vector<int> ans(maxN, -1);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int a = 1; a < maxN; ++a) 
    for (int b = a + 1; b < maxN - a; ++b) {
        int c2 = a * a + b * b;
        int c = sqrt(c2);
        if (c * c != c2) continue;

        int sum = a + b + c;
        if (sum > maxN) break;

        if (ans[sum] < a * b * c)
          ans[sum] = a * b * c;
    }

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << ans[n] << '\n';
  }
}