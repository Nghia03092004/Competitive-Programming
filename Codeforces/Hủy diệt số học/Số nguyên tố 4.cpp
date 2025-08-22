#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
int a[N];

bool nt(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return n > 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (nt(a[i])) ++cnt;
	}
	cout << cnt;
}