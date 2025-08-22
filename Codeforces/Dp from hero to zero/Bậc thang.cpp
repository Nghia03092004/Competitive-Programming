#include<stdio.h>
#include<math.h>

int mod = 14062008;
int hong[100005], dp[100005];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d" ,&x);
		hong[x] = 1;
	}
	dp[1] = 1;
	if (hong[2] == 1) dp[2] = 0;
	else dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		if (!hong[i]) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		}
	}
	printf("%d", dp[n]);
}