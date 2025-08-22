#include<stdio.h>
#include<math.h>
const int N = 100001;
int t[N], r[N], dp[N];

int min (int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n - 1; i++) 
		scanf("%d", &r[i]);
	dp[1] = t[1];
	dp[2] = min(t[1] + t[2], r[1]);
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
	}
	printf("%d", dp[n]);
}