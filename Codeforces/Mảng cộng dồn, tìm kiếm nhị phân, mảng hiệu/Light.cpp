#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;

int m, n, k, ans;
vector <vi> a, b;
vector<vector<ii>> sw;

int cal(int type) {
	b = vector<vi> (n + 5, vi(m + 5, 0));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			int cur = (a[i][j] + b[i][j]) % 3;
			if (cur != type) {
				int u  = sw[i][j].fi, v = sw[i][j].se;
				if (u == 0 || v == 0) return 1e9;
				if (cur < type) cur = type - cur;
				else {
					cur = 3 - cur + type;
				}
				cnt += cur;
				b[i][j] += cur, b[u + 1][v +  1] += cur;
				b[i][v + 1] -= cur, b[u + 1][j] -= cur;
			}
		}
	}
	return cnt;
}
 

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	a = vector<vi> (n + 5, vi(m + 5, 0));
	sw = vector<vector<ii>> (n+5, vector<ii>(m+5, {0, 0}));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= k; i++) {
		int r, c, x, y;
		cin >> r >> c >> x >> y;
		sw[r][c] = {x, y};
	}
	ans = min(cal(1), cal(2));
	if (ans == 1e9) cout << -1;
	else cout << ans;
	return 0;
}