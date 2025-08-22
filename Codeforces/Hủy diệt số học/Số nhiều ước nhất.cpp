#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 2;
int a[N], b[N];
int n, ans = 0;

void sieve() {
	fill(b + 1, b + N + 1, 2);
	b[1] = 1;
	for (int i = 2; i <= N; i++) {
			for (int j = 2*i; j <= N; j += i) {
				b[j]++;
			}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans = max(ans, b[a[i]]);
	}
	cout << ans;
}