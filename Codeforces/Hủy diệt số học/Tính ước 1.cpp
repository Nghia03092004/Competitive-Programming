#include<bits/stdc++.h> 
using namespace std;

long long n; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans += 2;
		} 
	}
	long long tmp = sqrt(n);
	if (tmp * tmp == n) cout << ans - 1;
	else cout << ans;
}