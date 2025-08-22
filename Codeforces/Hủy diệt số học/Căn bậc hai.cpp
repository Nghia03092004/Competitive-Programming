#include<bits/stdc++.h>
using namespace std;

bool nt(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		if (a == 1) cout << 1 << " " << 1;
		else if (nt(a)) cout << 1 << " " << a;
		else {
			for (int i = sqrt(a); i >= 1; i--) {
				if (a % (i*i) == 0) {
					cout << i << " " << a/(i*i);
					break;
				} 
			}
		}
		cout << "\n";
	}
}