#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 20;
bool prime[N];

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
	int n; cin >> n;
	for (int i = n + 1; i <= N; i++) {
		if (prime[i]) {
			cout << i;
			break;
		}
	}
}