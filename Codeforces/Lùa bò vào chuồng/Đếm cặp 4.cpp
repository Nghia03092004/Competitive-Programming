#include<stdio.h>

int a[100001], b[100001], cnt1[100001], cnt2[100001];

int main() {
	int n, m; 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		++cnt1[a[i]];
	}	
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		++cnt2[b[i]];
	}	
	int count = 0; 
	for (int i = 0; i < 100001; i++) {
		count += cnt1[i] * cnt2[i];
	}
	printf("%d", count);
}