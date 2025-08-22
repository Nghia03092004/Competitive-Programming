#include<bits/stdc++.h>
using namespace std;

const int N = 7e5 + 4;
int n, L;
int x[N], d[N], t[N], v[N], cnt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> L;
	for (int i = 1; i <= n ; i++) cin >> x[i];
	for (int i = 1; i <= n ; i++) cin >> d[i];
	for (int i = 1; i <= n ; i++) cin >> t[i];
	for (int i = 1; i <= n ; i++) cin >> v[i];	
	int s = 3e5;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[x[i] + d[j] + s]++;
		} 
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += cnt[L - t[i] - v[j] + s];
		}
	}
	cout << ans;
}