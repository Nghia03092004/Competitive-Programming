#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, k, dp[N];

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i <= k; i++)  dp[i] = i + 1;
	for (int i = k + 1; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - k - 1]) % mod;
	cout << dp[n];
	return 0;
	
} 