#include<stdio.h>

int a[1000001], b[1000001], c[1000001];
int cnt1[1000001], cnt2[1000001], cnt3[1000001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		++cnt1[a[i]];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		++cnt2[b[i]];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		++cnt3[c[i]];
	}
	int count = 0;
	for (int i = 1; i < 1000001; i++) {
		count += cnt1[i] * cnt2[i] * cnt3[i];
	}
	printf("%d", count);
	return 0;
}