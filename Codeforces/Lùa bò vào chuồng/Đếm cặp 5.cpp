#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 8; // chu y gioi han mang 0 <= a[r] % mod < 10 ^ 6
int n, mod;
long long a[N];
int cnt[N];

int main() {
	cin >> n >> mod;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int r = 1; r <= n; r++) {
		ans += cnt[a[r] % mod];
		cnt[a[r] % mod]++;
	}
	cout << ans;
}