#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 1;
bool prime[N];
int n;
char k;
int a[N];
char c[N];

void sieve() {
	for (int i = 1; i <= N; i++) prime[i] = true;
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) 
		if (prime[i])
			for (int j = i*i; j <= N; j += i) prime[j] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (prime[i] && c[i] == k && a[i] > max) max = a[i];
	} 
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == max && prime[i] && c[i] == k) ++cnt;
	}
	if (cnt == 0) cout << 0 << " " << 0;
	else cout << cnt << " " << max;
}