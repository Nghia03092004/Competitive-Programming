#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 2;
const int mod = 1e9 + 7;
int n, dp[N];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	cout << dp[n];
}