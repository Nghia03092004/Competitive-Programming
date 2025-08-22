#include<bits/stdc++.h> 
using namespace std;

long long n;
bool check(long long n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return n > 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (check(i)) ++cnt;
			if (n / i != i && check(n / i)) ++cnt;
		}
	}
	cout << cnt;
}