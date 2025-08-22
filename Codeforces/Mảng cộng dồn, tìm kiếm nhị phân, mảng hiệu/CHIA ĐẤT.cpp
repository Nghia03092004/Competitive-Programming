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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N =  505;

int n, ans = 1e18, a[N][N], pref[N][N];

main() {
	fast
	cin >> n;
	For (i, 1, n) For (j, 1, n) {
		cin >> a[i][j];
		pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
	}
	For (i, 1, n) For (j, 1, n) {
		int a = pref[i][j];
		int b = pref[n][j] - a;
		int c = pref[i][n] - a;
		int d = pref[n][n] - a - b - c;
		ans = min(ans, max({a, b, c, d}) - min({a, b, c, d}));
	}
	cout << ans;
	return 0;
}
