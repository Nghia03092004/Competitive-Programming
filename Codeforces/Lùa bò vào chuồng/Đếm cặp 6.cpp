#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, mod;
long long a[N];
long long cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> mod;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long ans = 0, x = 1e9 + 3;
	for (int r = 1; r <= n; r++) {
		ans += cnt[(a[r] + x) % mod];
		cnt[(a[r] + x) % mod]++;
	}
	cout << ans;
}