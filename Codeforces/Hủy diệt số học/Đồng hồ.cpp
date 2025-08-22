#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m; long long n;
	cin >> m >> n;
	int ans = (m + (n % 60)) % 60;
	cout << ans;
}