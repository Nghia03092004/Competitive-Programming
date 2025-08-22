#include<stdio.h>

const int N= 1000001;
const int mod = 1000000007;
int dp[N];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000000; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}