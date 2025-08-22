#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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
	ll n;
	cin >> n;
	for (int i = n/2; i >= 1; i--) {
		if (gcd(i, n - i) == 1) {
			cout << i*(n - i);
			return 0;
		}
	}
}
//lcm(a, b) max <=> gcd(a, b) = 1;
// 10
// 1 2 3 4 5 6 7 8 9 10
// 10 and 0
// 9 and 1
// 8 and 2
// 7 and 3
// 6 and 4
// 5 and 5
// o giua co tich so cang lon --> duyet vong lap tu n /2 --> 1