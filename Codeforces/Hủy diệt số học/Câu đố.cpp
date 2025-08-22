#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 4;
int cnt[N];
int n, k, ans = 0;

void sieve() {
	fill(cnt + 1, cnt + N + 1, 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 2*i; j <= N; j += i)
			cnt[j]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == k) ++ans;
	}
	cout << ans;
}