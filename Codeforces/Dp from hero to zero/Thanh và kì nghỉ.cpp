#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e5 + 5;
int n, a[N], b[N], c[N], dp1[N], dp2[N], dp3[N];

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		dp1[i] = max(dp2[i - 1], dp3[i - 1]) + a[i];
		dp2[i] = max(dp1[i - 1], dp3[i - 1]) + b[i];
		dp3[i] = max(dp1[i - 1], dp2[i - 1]) + c[i];
	}
	cout << max({dp1[n], dp2[n], dp3[n]});
	return 0;
}