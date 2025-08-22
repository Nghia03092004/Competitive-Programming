#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma target("av2")
#include<bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = INT_MAX;
int q, n, k, a[N], b[N], dp[N][N];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> q;	
	while (q--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i]; 
		}
		
		for (int i = 0; i <= n; i++) 
			for (int j = 0; j <= k; j++) 
				dp[i][j] = -inf;
				
		for (int i = 1; i <= n; i++) {
			dp[i][1] = b[i];
			for (int j = 2; j <= k; j++) {
				for (int x = 1; x < i; x++) {
					if (a[i] != a[x]) 
						dp[i][j] = max(dp[i][j], dp[x][j - 1] + b[i]);
				}
			}
		}
		
		
		int ans = 0;
		for (int i = 1; i <= n; i++) 
			ans = max(ans, dp[i][k]);
			
		(ans != 0) ? cout << ans << '\n' : cout << -1 << '\n';
	}
	
	
	return 0;
}