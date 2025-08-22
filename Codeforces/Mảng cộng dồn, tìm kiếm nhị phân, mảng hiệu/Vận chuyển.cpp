#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define For(i, l, r) for (auto i = (l); i <= (r); i++)
#define Ford(i, l, r) for (auto i = (l); i >= (r); i--) 
#define ii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) ((x).begin(), (x).end)
typedef vector<int> vi;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int n, m, ta, tb, k, ans = 0, a[N], b[N];

int bs(int x) {
	int l = 0, r = m - 1, res = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (b[mid] >= x) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

main() {
	fast 
	cin >> n >> m >> ta >> tb >> k;
	For (i, 0, n - 1) cin >> a[i];
	For (i, 0, m - 1) cin >> b[i];
	if (k >= n || k >= m) {
		cout << -1;
		return 0;
	}
	For (i, 0, k) {
		int tmp = bs(a[i] + ta);
		if (tmp != -1) {
			if (tmp + k - i > m) {
				cout << -1;
				return 0;
			} else ans = max(ans, b[tmp + k - i] + tb);
		}
	}
	cout << ans;
	return 0;
}