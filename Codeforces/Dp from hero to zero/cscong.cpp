#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
const int D = 1e3 + 5;
int n, a[N], dp[N][D], ans = -1e9;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= D; j++) dp[i][j] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) 
				dp[i][a[i] - a[j]] = dp[j][a[i] - a[j]] + 1;
		} 
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= D; j++) 
			ans = max(ans, dp[i][j]);
	cout << ans;
}