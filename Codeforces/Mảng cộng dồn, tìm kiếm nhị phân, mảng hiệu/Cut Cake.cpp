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
const int N = 305;

int n, m, ans = -1e18, a[N][N], f[N][N];

main() {
	fast
	cin >> n >> m;
	For (i, 1, n) For (j, 1, m) {
		cin >> a[i][j];
		f[i][j] = f[i - 1][j] + a[i][j];
	}
	For (x1, 1, n) For (x2, x1, n) {
		int sum = 0, mi = 0;
		For (j, 1, m) {
			sum += f[x2][j] - f[x1 - 1][j];
			ans = max(ans, sum - mi);
			mi = min(mi, sum);
		}
	}
	cout << ans;
	return 0;
}
