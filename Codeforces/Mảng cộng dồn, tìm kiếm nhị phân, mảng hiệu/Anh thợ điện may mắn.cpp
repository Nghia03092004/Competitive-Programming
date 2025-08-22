#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e6 + 4;
int n, r, k, a[N], pref[N];

bool check(int mid) {
	int b[n + 10] = {0};
	int cnt = 0;
	for (int i = 1; i <= n; i++) b[i] = pref[i];
	for (int i = 1; i <= n; i++) {
		int x = max(1ll*0, i - r - 1);
		int y = min(n, i + r);
		b[y] = b[y - 1] + a[y]; 
		int tmp = b[y] - b[x];
		if (mid > tmp) {
			cnt += mid - tmp;
			if (y == n) b[y - 1] += mid - tmp; //modulo
			else b[y] += mid - tmp;
		}
	}
	return cnt <= k;
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); // remember please huhu
	cin >> n >> r >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	int l = 0, r = 1e12, ans = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout << ans;
	return 0;
}