#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int S = 1e4 + 5;
int n, sum = 0, ans = 1e9, a[N], dp[N][S];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j >= a[i]) dp[i][j] = dp[i - 1][j - a[i]] | dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j];
		}
	}
	for (int j = 0; j <= sum; j++) 
		if (dp[n][j]) ans = min(ans, abs(j - (sum - j)));
	cout << ans;
}


#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 1;
const int S = 1e4 + 1;
int n;
int a[N], dp[N][S];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	dp[1][0] = 1;
	dp[1][a[1]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			if (a[i] <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]]);
			}   
			else dp[i][j] = dp[i - 1][j];
		}
	}
	int ans = 1e18;
	for (int i = 0; i <= s; i++) {
		if (dp[n][i]) ans = min(ans, abs(i - (s - i)));
	}
	cout << ans;
}