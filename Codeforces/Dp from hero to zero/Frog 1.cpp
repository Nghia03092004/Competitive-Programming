#include<stdio.h>
#include<math.h>

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	int n;
	scanf("%d", &n);
	int h[100005];
	int f[100005];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	f[1] = 0;
	f[2] = abs(h[2] - h[1]);
	for (int i = 3; i <= n; i++) {
		f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
	}
	printf("%d", f[n]);
	return 0;
}