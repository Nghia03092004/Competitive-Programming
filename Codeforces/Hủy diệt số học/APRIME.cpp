#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 3;
int a[N], b[N], n, cnt = 0;
bool prime[N];

void sieve()  {
	for (int i = 1; i <= N; i++) prime[i] = true;
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) 
		if (prime[i])
			for (int j = i*i; j <= N; j += i) prime[j] = false;
	for (int i = 1; i <= N; i++) {
		if (prime[i]) b[++cnt] = i;
	}
}
 
int ans (int a) {
	int res = 0; 
	for (int i = 1; i <= cnt; i++) {
		if (b[i] >= a) break;
		for (int j = 1; j <= cnt; j++) {
			int x = b[i] * b[i] + b[j] * b[j] * b[j];
			if (x >= a) break;
			if (prime[a - x]) ++res; 
		}
	}
	return res;
} 
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cout << ans(a[i]) << "\n";
	return 0;
}