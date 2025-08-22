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
const int N = 1e3 + 5;

int n, k, ans = 0, a[N][N], pref[N][N];

main() {
	fast
	cin >> n >> k;
	For (i, 1, n) For (j, 1, n) {
		cin >> a[i][j];
		pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
	}
	For (i, k, n) {
		For (j, k, n) {
			int x1 = i - k + 1, y1 = j - k + 1;
			ans = max(ans, pref[i][j] - pref[i][y1 - 1] - pref[x1 - 1][j] + pref[x1 - 1][y1 - 1]);
		}
	}
	cout << ans;
	return 0;
}
 