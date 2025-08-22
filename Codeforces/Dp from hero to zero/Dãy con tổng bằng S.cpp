#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e3 + 5;
const int mod = 1e9 + 7;
int n, S, a[N];
int dp[N][M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> S;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1; // day rong co tong 0
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= S; j++) {
			if (j >= a[i]) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i]]) % mod;
			else dp[i][j] = dp[i - 1][j];
		}
	cout << dp[n][S];
	return 0;
}