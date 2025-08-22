#include<bits/stdc++.h>
using namespace std;

bool check(long long n) {
	long long tmp = sqrt(n);
	if (tmp * tmp == n) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long x, y;
	cin >> x >> y;
	long long a = sqrt(x), b = sqrt(y);
	if (check(x)) cout << b - a + 1;
	else cout << b - a;
}