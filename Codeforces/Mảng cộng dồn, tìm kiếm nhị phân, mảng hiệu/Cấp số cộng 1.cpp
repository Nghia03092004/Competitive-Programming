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

int n, q, a[N], diff[N], f[N];

main() {
	fast
	cin >> n;
	For (i, 1, n) cin >> a[i];
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		diff[l]++, diff[r + 1]--;
		f[r + 1] -= r - l + 1;
	}
	For (i, 1, n) diff[i] += diff[i - 1];
	For (i, 1, n) diff[i] += diff[i - 1], f[i] += f[i - 1];
	For (i, 1, n) cout << a[i] + diff[i] + f[i] << " ";
	return 0;
}