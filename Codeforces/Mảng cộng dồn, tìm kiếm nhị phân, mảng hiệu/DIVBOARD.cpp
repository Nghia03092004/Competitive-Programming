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
const int N = 1e3 + 5;

int m, n, ans = 1e18, a[N][N], pref[N][N];

main() {
	fast
	cin >> m >> n;
	For (i, 1, m) For (j, 1, n) {
		cin >> a[i][j];
		pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
	}
	For (i, 1, m - 1) {
		int a = pref[i][1], b = pref[i][n] - a;
		For (j, 2, n - 1) {
			int x = pref[i][j], y = pref[i][n] - x;
			if (abs(x - y) < abs(a - b)) a = x, b = y;
		}
		int c = pref[m][1] - pref[i][1], d = pref[m][n] - pref[i][n] - c;
		For (j, 2, n - 1) {
			int z = pref[m][j] - pref[i][j], t = pref[m][n] - pref[i][n] - z;
			if (abs(z - t) < abs(c - d)) c = z, d = t;
		}
		ans = min(ans, max({a, b, c, d}) - min({a, b, c, d}));
	}
	cout << ans;
	return 0;
}
 