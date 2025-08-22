#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long s[N];
int t;

void Sum() {
	s[1] = 1;
	for (long long i = 2; i <= N; i++) {
		s[i] = s[i -  1] + i*i;
	}
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Sum();
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		cout << s[N] << "\n";
	}
}