#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 15;
int a[N], n;
ll x, ans = 1;
 
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
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans = lcm(ans, a[i]);
	}
	ll a = x/ans;
	if (a * ans == x) cout << x;
	else cout << (a + 1)*ans; 
}