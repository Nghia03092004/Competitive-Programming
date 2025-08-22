#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll decimal(char c[]) {
	ll ans = 0; int n = strlen(c);
	for (int i = 0; i < n; i++) {
		if (c[i] == '1') ans += pow(2, n - i - 1);
	}
	return ans;
}
 
bool check(ll n) {
	ll tmp = sqrt(n);
	if (tmp * tmp == n) return true;
	else return false;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char c[100], d[100];
	gets(c); gets(d);
	ll cnt = 0;
	ll x = decimal(c), y = decimal(d);
	ll a = sqrt(x), b = sqrt(y);
	if (check(x)) cout << b - a + 1;
	else cout << b - a;

}