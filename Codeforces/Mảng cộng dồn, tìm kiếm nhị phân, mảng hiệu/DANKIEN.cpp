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
const int N = 1e6 + 5;

int n, ans = 1e18;
int a[N], x[N], num[N], f[N];

main() {
	fast
	cin >> n;
	For (i, 1, n) cin >> a[i];
	For (i, 1, n) cin >> x[i];
	For (i, 1, n) {
		num[i] = num[i - 1] + a[i];// tong sl kien o j < i di chuyen den i va sl o i
		f[i] = f[i - 1] + a[i]*x[i]; // total_distance cua kien o cac vt j <= i so voi goc toa do
	}
	For (i, 1, n) 
		ans = min(ans, num[i]*x[i] - f[i] + (f[n] - f[i]) - (num[n] - num[i])*x[i]);
	cout << ans;
	return 0;
}
 