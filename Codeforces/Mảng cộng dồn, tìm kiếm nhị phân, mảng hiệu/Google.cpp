#include<bits/stdc++.h>
using namespace std;

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
const int M = 3e4 + 5;
const int N = 1e3 + 4;
int m, n, k, l, r, ans = 0, cnt = 0;
int diff[M][N];

int sqr(int a) {
	return a*a;
}

int calc(int a, int b, int c, int d) {
	return sqr(a - c) + sqr(b - d);
}

int main() {
	fast
	cin >> m >> n >> k; // m hang, n cot
	while (k--) {
		int x, y, R, b;
		cin >> x >> y >> R >> b;
		diff[max(1, y - R)][x] += b;
		diff[min(m, y + R) + 1][x] -= b;
		l = max(1, y - R), r = min(m, y + R);
		For (i, x + 1, n) {
			while (l <= r && calc(r, i, y, x) > sqr(R)) r--;
			while (l <= r && calc(l, i, y, x) > sqr(R)) l++;
			if (l > r) break;
			diff[l][i] += b, diff[r + 1][i] -= b;
		}
		l = max(1, y - R), r = min(m, y + R);
		Ford (i, x - 1, 1) {
			while (l <= r && calc(r, i, y, x) > sqr(R)) r--;
			while (l <= r && calc(l, i, y, x) > sqr(R)) l++;
			if (l > r) break;
			diff[l][i] += b, diff[r + 1][i] -= b;
		}
	}
	For (i, 1, m) For (j, 1, n) {
		diff[i][j] += diff[i - 1][j];
		if (diff[i][j] > ans) ans = diff[i][j], cnt = 1;
		else if (diff[i][j] == ans) ++cnt;
	}
	cout << ans << endl << cnt;
	return 0;
}
