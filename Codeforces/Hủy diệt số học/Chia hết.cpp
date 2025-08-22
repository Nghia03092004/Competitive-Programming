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
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	ll c = lcm(x, y);
	ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
	if (a % x == 0) cnt1 = b/x - a/x + 1;
	else cnt1 = b/x - a/x;
	if (a % y == 0) cnt2 = b/y - a/y + 1;
	else cnt2 = b/y - a/y;
	if (a % c == 0) cnt3 = b/c - a/c + 1;
	else cnt3 = b/c - a/c;
	cout << cnt1 + cnt2 - cnt3;
}