#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
int n;
int a[N], cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0, x = 2e5;
	for (int r = 1; r <= n; r++) {
		ans += cnt[a[r] - r + x];
		cnt[a[r] - r + x]++;
	}
	cout << ans;
}