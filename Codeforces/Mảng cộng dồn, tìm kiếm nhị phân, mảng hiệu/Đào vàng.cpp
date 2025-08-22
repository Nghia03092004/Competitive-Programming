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
typedef vector<ii> vii;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 5e4 + 5;

int n, k, a[N];

bool check(int R) {
	int pos = a[1], cnt = 1;
	For (i, 2, n) 
		if (pos + 2*R < a[i]) {
			pos = a[i];
			++cnt;
		}
	return cnt <= k;
}

main() {
	fast
	cin >> n >> k;
	For (i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = 1e18, ans;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ans;
	return 0;
}
 