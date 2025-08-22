#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, l, r, cnt = 0;
	cin >> k >> l >> r;
	string a = to_string(k);
	for (int i = l; i <= r; i++) {
		string s = to_string(i);
		if ((int)s.find(a) != -1)++cnt;
	}
	cout << cnt;
}