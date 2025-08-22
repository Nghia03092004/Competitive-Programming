#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 15;
const int S = 1e3 + 4;
int n, sum = 0, idx = 0;
int s[N], dp[N][S];

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i], sum += s[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			for (int x = 1; x <= s[i]; x++)
				if (j >= x) dp[i][j] += dp[i - 1][j - x];
		}
	}
	for (int i = 1; i <= sum; i++)
		if (dp[n][i] > dp[n][idx]) idx = i;
	cout << idx;
} 