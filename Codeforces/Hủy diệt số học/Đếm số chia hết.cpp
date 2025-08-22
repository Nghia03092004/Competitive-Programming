#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long k, a, b;
	cin >> k >> a >> b;
	if (a % k == 0) cout << b/k - a/k +1;
	else cout << b/k - a/k;
}