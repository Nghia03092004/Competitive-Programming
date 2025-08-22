#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			int tmp = i;
			while (tmp != 1 && tmp % 2 == 0) {
				tmp /= 2;
				++cnt;
			}
		}
	}
	cout << cnt;
}