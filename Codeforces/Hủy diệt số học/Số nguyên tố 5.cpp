#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int M = 5e6 + 1;
int a[N], prime[M];
int n;

void sieve() {
	for (int i = 1; i <= M; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	for (int i = 2; i <= sqrt(M); i++) {
		if (prime[i])
			for (int j = i*i; j <= M; j += i) 
				prime[j] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (prime[a[i]]) ++ans;
	}
	cout << ans;
}