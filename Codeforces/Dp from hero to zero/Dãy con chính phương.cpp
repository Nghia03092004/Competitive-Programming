#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int n, ans = 0;
int a[N], dp[N];

bool isSquare(int n) {
	if (n == 0) return false;
	int tmp = sqrt(n);
	if (tmp * tmp == n) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = max(1, i - 10); j < i; j++) 
			if (isSquare(abs(a[i] - a[j]))) 
				dp[i] = max(dp[i], dp[j] + 1); 
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
}