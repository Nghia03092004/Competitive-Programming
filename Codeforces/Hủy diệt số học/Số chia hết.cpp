#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n < 4) cout << -1;
	else if (n == 4) cout << 2310;
	else {
		cout << "1";
		int tmp = 1;
		for (int i = 1; i < n; i++) tmp = (tmp * 10) % 2310;
		tmp = 2310 - tmp;
		for (int i = 1; i < n - 4; i++) cout << '0';
		if (tmp >= 1000)  cout << tmp;
		else if (tmp >= 100 && tmp < 1000) cout << '0' << tmp;
		else if (tmp >= 10 && tmp < 100) cout << '00' << tmp;
		else cout << '000' << tmp; 
	}
}