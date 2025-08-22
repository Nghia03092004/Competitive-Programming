#include<stdio.h>

int a[100001];
int count[100001];

int check(int count[]) {
	for (int i = 0; i < 100001; i++)
		if (count[i] >= 2) return 0;
	return 1; 
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		++count[a[i]];
	if (check(count)) printf("YES");
	else printf("NO");
	return 0;
}