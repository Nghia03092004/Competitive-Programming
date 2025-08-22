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
const int N = 505;
 
int m, n, q, p, R = 0, D = 0;
int a[N][N], f[N][N];
 
int calc(int i, int v, int t) {
	i = (i + D) % m;
	v = (v + R) % n, t = (t + R) % n;
	if (v <= t) return f[i][t] - f[i][v - 1];
	else return f[i][n - 1] - abs(f[i][t] - f[i][v - 1]);
}
 
main() {
	fast
	cin >> m >> n;
	For (i, 0, m - 1) For (j, 0, n - 1) {
		cin >> a[i][j];
		f[i][j] = f[i][j - 1] + a[i][j];
	}
	cin >> q;
	while (q--) {
		cin >> p;
		if (p == 0) {
			int x, y;
			cin >> x >> y;
			R += x; D += y;  
		}
		else {
			int u, v, s, t, rsl = 0;
			cin >> u >> v >> s >> t;
			For (i, u - 1, s - 1)
				rsl += calc(i, v - 1, t - 1);
			cout << rsl << endl;
		}
	}
	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl "\n"
// const int N = 5e2 + 10;
// int n, m, q, p, D, R;
// int a[N][N], f[N][N]; 

// int result(int i, int v, int t) {
// 	i = (i + D) % m; if (i == 0) i = m; //modulo
// 	v = (v + R) % n; if (v == 0) v = n;
// 	t = (t + R) % n; if (t == 0) t = n;
// 	if (v <= t) return f[i][t] - f[i][v - 1];
// 	else return f[i][n] - f[i][v - 1] + f[i][t];
// }

// main() {
// 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	cin >> m >> n;
// 	for (int i = 1; i <= m; i++) {
// 		for (int j = 1; j <= n; j++) {
// 			cin >> a[i][j];
// 			f[i][j] = f[i][j - 1] + a[i][j];
// 		}
// 	}
// 	cin >> q;
// 	while (q--) {
// 		cin >> p;
// 		if (p == 0) {
// 			int x, y;
// 			cin >> x >> y;
// 			D = (D + y) % m;
// 			R = (R + x) % n;
// 		}
// 	    else {
// 			int u, v, s, t, ans = 0;
// 			cin >> u >> v >> s >> t;
// 			for (int i = u; i <= s; i++) 
// 			ans += result(i, v, t);
// 			cout << ans << endl;
// 		}
// 	}
// }