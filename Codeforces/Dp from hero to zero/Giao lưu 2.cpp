#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, k;
int dp[N];

main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = (2*dp[i - 1]) % mod;
		if (i - k - 1 >= 0) 
			dp[i] = (dp[i] - dp[i - k - 1]  + mod*mod) % mod;
		else if (i - k == 0)
			dp[i] = (dp[i] - 1 + mod*mod) % mod;
	}
	cout << dp[n];
	return 0;
}