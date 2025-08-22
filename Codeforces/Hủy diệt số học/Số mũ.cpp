#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i % k == 0) {
				int tmp = i;
				while (tmp % k == 0) {
					tmp /= k;
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}