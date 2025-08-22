#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e7 + 10;
bool prime[N];
 
void sieve() {
	for (int i = 1; i <= N; i++) 	
		prime[i] = true;
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) 
		if (prime[i])
			for (int j = i*i; j <= N; j += i)
				prime[j] = false;
}
 
bool check(int n) {
	if (prime[n]) {
		int l = n, r = n;
		while (l--) {
			if (prime[l]) break;
		}
		while (r++) {
			if (prime[r]) break;
		}
		if (2*n == r + l) return true;
		else return false;
	}
	else return false;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	sieve();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (check(n)) cout << "YES\n";
		else cout << "NO\n";
	}
}