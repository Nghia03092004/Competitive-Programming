#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int prime[N];
int a[N];
int cnt[N];

void sieve() {
	for (int i = 1; i <= N; i++) prime[i] = i;
	for (int i = 2; i <= sqrt(N); i++) 
		if (prime[i] == i) 
			for (int j = i*i; j <= N; j += i) 
				if (prime[j] == j) prime[j] = i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= k; i++) {
		cnt[prime[i]]++;
	}
	for (int i = 1; i <= n; i++) cout << cnt[a[i]] << "\n";
}