#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
int n, k, ans = 1;
int a[N], prime[N], fact[N];

void Sieve() {
	for (int i = 1; i <= N; i++) prime[i] = i;
	for (int i = 2; i <= sqrt(N); i++) 
		if (prime[i] == i) 
			for (int j = i*i; j <= N; j += i) 
				if (prime[j] == j) prime[j] = i;
}

void Analyze(int n) {
	int cnt = 0;
	while (prime[n] != n) {
		++cnt;
		if (prime[n] != prime[n / prime[n]]) {
			if (cnt > fact[prime[n]]) fact[prime[n]] = cnt;
			cnt = 0;
		}
		n /= prime[n];
	}
	if (n != 1) {
		++cnt;
		if (cnt > fact[n]) fact[n] = cnt;
	}
}
 
void Power(int radix, int ex) {
	for (int i = 1; i <= ex; i++) 
		ans = (ans * radix) % mod;
}
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Sieve();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Analyze(a[i]);
	}
	k = a[k];
	while (prime[k] != k) {
		fact[prime[k]]--;
		k /= prime[k];
	} 
	if (k != 1) fact[k]--;
	for (int i = 2; i <= N; i++) {
		fact[i] -= fact[i] % 2;
		Power(i, fact[i]);
	}
	cout << ans;
} 
// small town boy in a big arcade