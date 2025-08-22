#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;
int q, n, a[N];

bool check(int num) {
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		if (tmp == 0) tmp = num;
		if (tmp >= a[i]) tmp -= a[i];
		else return false;
	}
	if (tmp == 0) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> q;
	while (q--) {
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		int ans = 1; 
		if (check(1)) ++ans; 
		for (int i = 2; i <= sqrt(sum); i++) {
			if (check(i)) ++ans;
			if (sum / i != i && check(sum/i)) ++ans;
		}
		cout << ans << "\n";
	}
}