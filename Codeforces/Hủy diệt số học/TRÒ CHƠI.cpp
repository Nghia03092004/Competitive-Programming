#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m, n, x, y;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> x >> y;
	ll tmp = lcm(x, y);
	if (m % tmp == 0) cout << n/tmp - m/tmp + 1;
	else cout << n/tmp - m/tmp;  
}