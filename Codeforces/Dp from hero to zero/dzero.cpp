#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 1;
int q, k, dp[N];
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int x = sqrt(i); x >= 2 ; x--) {
			if (i % x == 0) {
				dp[i] = min(dp[i], dp[max(x, i/x)] + 1);
			}
		}
	}
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		cout << dp[k] << "\n";
	}
}