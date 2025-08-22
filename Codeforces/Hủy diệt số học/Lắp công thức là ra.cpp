#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll c = b - a ;
	cout << c - a % c;
}