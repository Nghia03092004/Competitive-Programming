#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7 + 1;
long long n; 
long long a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i != i) {
				a[++cnt] = i;
				a[++cnt] = n / i;
			}
			else a[++cnt] = i;
		}
	}
	sort(a + 1, a + cnt + 1);
	for (int i = 1; i <= cnt; i++) cout << a[i] << " ";
}