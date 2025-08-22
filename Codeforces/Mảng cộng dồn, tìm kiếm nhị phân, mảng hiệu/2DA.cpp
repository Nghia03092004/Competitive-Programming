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
const int N = 5e2 + 5;

int n, m, q, a[N][N], pref[N][N];

main() {
	fast
	cin >> n >> m >> q;
	For (i, 1, n) For (j, 1, m) {
		cin >> a[i][j];
		pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
	}
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}
 