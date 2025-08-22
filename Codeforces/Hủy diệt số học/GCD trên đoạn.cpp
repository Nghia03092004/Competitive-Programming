#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int a[N];
int n, k;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b); 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 1;
	for (int i = 1; i <= n - k; i++) {
		int tmp = a[i];
		for (int j = i + 1; j <= i + k - 1; j++) {
			tmp = gcd(tmp, a[j]);
			if (tmp < ans) break;
		}
		ans = max(ans, tmp);
	}
	cout << ans;
}