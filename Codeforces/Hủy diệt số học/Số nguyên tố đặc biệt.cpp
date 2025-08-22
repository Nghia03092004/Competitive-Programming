#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
bool prime[N];

void sieve() {
	for (int i = 1; i <= N; i++) prime[i] = true;
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) 
		if (prime[i])
			for (int j = i*i; j <= N; j += i) 
				prime[j] = false;
}

bool check(int n) {
	if (prime[n]) {
		int sum = 0;
		while (n) {
			sum += n % 10;
			n /= 10;
		}
		if (prime[sum]) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	sieve();
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (check(i)) cout << i << " "; 
	}
}