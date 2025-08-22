#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int mod = 1e9 + 7;
int m, n, a[N][N], dp[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '.') a[i][j] = 1;
		}
	dp[1][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j]) 
				dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	cout << dp[m][n];
	return 0;
}