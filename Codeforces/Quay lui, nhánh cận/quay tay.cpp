#include<bits/stdc++.h>
using namespace std;

string s;
int n, cnt[5];

void print() {
	if (n % 2 == 0) {
		for (int i = 1; i <= n/2; i++) cout << s[i];
		for (int i = n/2; i >= 1; i--)  cout << s[i];
		cout << "\n";
	} else for (int i = 1; i <= 4; i++) {
		if (cnt[i] >= 1) {
			for (int i = 1; i <= n/2; i++) cout << s[i];
			cout << (char)(64 + i);
			for (int i = n/2; i >= 1; i--) cout << s[i];
			cout << "\n";
		}
	}
}

void Try(int i) {
	for (char x = 'A'; x <= 'D'; x++) {
		int k = x - 64;
		if (cnt[k] >= 2) {
			s[i] = x;
			cnt[k] -= 2;
			if (i == n/2) print();
			else Try(i + 1);
			cnt[k] += 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 4; i++) cin >> cnt[i];
	if (n == 1) {
		for (int i = 1; i <= 4; i++) {
			if (cnt[i] >= 1) {
				cout << (char)(i + 64) << "\n";
			}
		}
	}
	Try(1);
}