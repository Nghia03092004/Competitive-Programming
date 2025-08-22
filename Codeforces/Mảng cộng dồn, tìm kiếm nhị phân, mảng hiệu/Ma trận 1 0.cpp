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
const int N = 1e6 + 5;

int q, n, m, h, w;
vector <vi> a, pref, diff;

main() {
	fast
	cin >> q;
	while (q--) {
		bool flag = true;
		cin >> n >> m >> h >> w;
		a = vector<vi> (n + 5, vi(m + 5, 0));
		pref = vector<vi> (n + 5, vi(m + 5, 0));
		diff = vector<vi> (n + 5, vi(m + 5, 0));
		For (i, 1, n) For (j, 1, m) {
			cin >> a[i][j];
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
			diff[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
		}
		For (i, h, n) For (j, w, m) {
			int x = i - h + 1, y = j - w + 1; //trai tren
			if (pref[i][j] - pref[x - 1][j] - pref[i][y - 1] + pref[x - 1][y - 1] == 0) {
				diff[x][y]++, diff[i + 1][j + 1]++;
				diff[x][j + 1]--, diff[i + 1][y]--;
			}
		}
		For (i, 1, n) For (j, 1, m) {
			a[i][j] = diff[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			if (a[i][j] == 0) { // chua danh dau
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
