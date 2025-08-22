#include<bits/stdc++.h>
using namespace std;

#define ld long double
const int N = 55;
int n, q, x;
double a[N], dp[N];

double calc(double money, int i, int j) {
	return money*(a[i]/a[j] - 0.02);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--)  {
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i];
		dp[0] = x;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			for (int j = 1; j < i; j++) {
				dp[i] = max(dp[i], calc(dp[j - 1], i, j));
			}
		}
		cout << fixed << setprecision(5) << dp[n] << "\n";
	}
}