#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 1;
int mod = 1e9 + 7;
bool prime[N];
int a[N], n, cnt = 0;

void sieve(int n) {
	for (int i = 1; i <= n; i++) prime[i] = true;
	prime[1] =  false;
	for (int i = 2; i <= sqrt(n); i++) 
		if (prime[i]) 
			for (int j = i*i; j <= n; j += i)
				prime[j] = false;
	for (int i = 1; i <= n; i++)
		if (prime[i])	a[++cnt] = i;
}

ll LCM(int n) {
	ll ans = 1;
	for (int i = 1; i <= cnt; i++) {
		ll tmp = a[i];
		while (n >= tmp) tmp *= a[i];
		ans *= tmp / a[i];
		ans %= mod;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;	
	sieve(n);
 	cout << LCM(n);
}