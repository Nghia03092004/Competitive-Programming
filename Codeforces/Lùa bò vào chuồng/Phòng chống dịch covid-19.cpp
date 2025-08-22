#include<bits/stdc++.h>
using namespace std;

int n, ans;
int cnt[5];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; 
		cin >> x;
		cnt[x]++;
	}
	ans = cnt[4] + cnt[2]/2;
	cnt[2] %= 2;
	int tmp = min(cnt[1], cnt[3]); ans += tmp;
	cnt[1] -= tmp; cnt[3] -= tmp;
	if (cnt[3] > 0) {
		ans += cnt[2] + cnt[3];
	} else {
		if (cnt[2] == 0) ans += cnt[1]/4 + (cnt[1] % 4 != 0);
		else {
			if (cnt[1] >= 2) {
				cnt[1] -= 2;
				ans += cnt[1]/4 + (cnt[1] % 4 != 0) + 1;
			} else ans += 1;
		}
	}
	cout << ans;
}