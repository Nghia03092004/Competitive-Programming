#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int i = 2, ans = 0;
	while (n !=  1) {
		if (n % i == 0) {
			int tmp = 0;
			while (n % i == 0) {
				n /= i;
				tmp++;
			}
			if (tmp > ans) ans = tmp;
		}
		i++;
	}
	cout << ans;
}