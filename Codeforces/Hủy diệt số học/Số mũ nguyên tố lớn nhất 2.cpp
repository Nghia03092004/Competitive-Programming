#include<bits/stdc++.h>
using namespace std;
 
bool check(long long n) {
	for (int i = 2; i <= sqrt(n); i++) 
		if (n % i == 0) return false;
	return n > 1;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	if (check(n)) cout << 1;
	else {
		int ans = 0;
		for (int i = 2; i <= sqrt(n); i++) {
			int tmp = 0;
			while (n % i == 0) {
				n /= i;
				tmp++;
			}
			if (tmp > ans) ans = tmp;
		}
		cout << ans;
	}
}