#include<stdio.h>
 
int a[100001];
 
long long output(int cnt[], int n) {
	int count = 0; long long ans = 1;
	for (int i = n; i > 0; i--) {	
		while (cnt[i] - 2 >= 0) {
			ans *= i;
			cnt[i] -= 2;
			++count;
			if (count == 2) return ans;
		}
	}
	return -1;
}
 
int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		int n;
		scanf("%d", &n);
		int cnt[100001] = {0};
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			++cnt[a[i]];
		}
		printf("%lld\n", output(cnt, n));	
	}
	return 0;
}