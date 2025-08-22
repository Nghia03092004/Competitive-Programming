#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
int a[N], cnt[N];
int n, q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x;
		cin >> x;
		cout << cnt[x] << "\n";
	}
}