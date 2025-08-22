#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e5 + 5;
int n, W, w[105], v[105], ans = 0;
int dp[105][M];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> W;
	for (int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i];
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= W; j++) 
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
	for (int i = 0; i <= W; i++) 
		ans = max(ans, dp[n][i]);
	cout << ans;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int W = 1e5 + 3;
int n, m, w[N];
long long v[N];
long long dp[N][W];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i];
	dp[1][0] = 0;
	dp[1][w[1]] = v[1];
	for (int i = 2; i <= n ; i++) {
		for (int j  = 0; j <= m; j++) {
			if (w[i] <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			
			}
				else dp[i][j] = dp[i - 1][j];
		}
	}
	long long ans = 0;
	for (int j=1;j<=m;j++)
        ans = max(ans, dp[n][j]);
    cout << ans;
    
}