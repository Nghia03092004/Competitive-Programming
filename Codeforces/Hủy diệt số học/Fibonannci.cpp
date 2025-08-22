#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +3;
long long mod = 1e9 +7;
long long dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	cout << dp[n];
}