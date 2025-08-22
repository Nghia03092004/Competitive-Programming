#include<bits/stdc++.h>
using namespace std;

const int N = 4e5;
int a[N], cnt[N];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int x = 2e5;
	int ans = 0;
	for (int r = 1; r <= n; r++) {
		ans += cnt[a[r] - k + x];
		cnt[a[r] + x]++;
	}
	cout << ans;
}