#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int n, k;
int h[N], dp[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		dp[i] = 1e9;
	}
	for (int i = 1; i <= k; i++) {
		dp[i] = abs(h[i] - h[1]);
	}
	for (int i = k + 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j > 0);
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n];
}


// #include<stdio.h>
// #include<math.h>
// const int N = 100001;
// int h[N], dp[N];

// int min (int a, int b) {
// 	if (a < b) return a;
// 	return b;
// }

// int main() {
// 	int n, k;
// 	scanf("%d%d", &n, &k);
// 	for (int i = 1; i <= n; i++) {
// 		scanf("%d", &h[i]);
// 		dp[i] = 1000000009;
//  	}
		
// 	dp[1] = 0;
// 	for (int i = 2; i <= n; i++) {
// 		for (int j = 1; j <= k; j++) {
// 			if (i - j > 0) {
// 				dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
// 			}
// 		}
// 	}
// 	printf("%d", dp[n]);
// }