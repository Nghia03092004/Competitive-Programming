#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long l, r;
		cin >> l >> r;
		cout << (r + l)*(r - l + 1)/2 <<"\n";	
	}
}