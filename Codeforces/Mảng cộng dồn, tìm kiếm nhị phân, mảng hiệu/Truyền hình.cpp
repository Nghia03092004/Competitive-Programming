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
const int N = 5e5 + 5;

int n, ans = 0;
ii a[N];

bool cmp(ii a, ii b) {
	return a.se < b.se;
}

int bs(int pos) {
	int l = 1, r = pos, res;
	while (l <= r) {
		int mid = (l + r)/2;
		if (a[mid].se > a[pos].fi) {
			res = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return res;
}

main() {
	fast
	cin >> n;
	For (i, 1, n) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, cmp);
	For (i, 2, n) {
		ans += i - bs(i);
	}
	cout << ans;
	return 0;
}
 