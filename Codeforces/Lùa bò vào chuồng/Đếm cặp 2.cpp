#include<bits/stdc++.h>
using namespace std;

const int N = 6e5 + 1;
int n, k;
int a[N], cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int x = 3e5;
	int ans = 0;
	for (int y = 1; y <= n; y++) {
		for (int z = y + 1; z <= n; z++) {
			ans += cnt[k - a[z] - a[y] + x];
		}
		cnt[a[y] + x]++; // cap nhat 
	}
	cout << ans;
}