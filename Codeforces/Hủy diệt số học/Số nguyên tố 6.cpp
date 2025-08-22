#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int M = 1e6 + 5;
bool prime[N];
int a[N], b[M], n, cnt = 0, ans = 0;

void sieve() {
	fill(prime, prime + N + 1, true);
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++)
		if (prime[i])
			for (int j = i*i; j <= N; j += i) prime[j] = false;
	for (int i = 2; i <= N; i++)
		if (prime[i]) a[++cnt] = i;
}

bool check (int x) {
	for (int i = 1; i <= cnt; i++) {
		if (a[i] > sqrt(x)) break;
		if (x % a[i] == 0) return false;
	}
	return x > 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (check(b[i])) ++ans;
	}
	cout << ans;
}
// small town boy in a big arcade