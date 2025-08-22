#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 1;
ll a[N]; int n;
ll ans = -1e18;

ll cnt(ll n) {
	int tmp = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (i*i == n) tmp += 1;
			else tmp += 2;
		}
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans = max(ans, cnt(a[i]));
	}
	cout << ans;
}