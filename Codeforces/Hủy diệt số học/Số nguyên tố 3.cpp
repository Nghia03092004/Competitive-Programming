#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int prime[N];

void sieve() {
	for (int i = 1; i <= N; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	for (int i = 1; i <= sqrt(N); i++) {
		if (prime[i])
			for (int j = i*i; j <= N; j+= i) {
				prime[j] = false;
			}
	}
}

int main() {
	sieve();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (prime[i]) cout << i << " ";
	}
}