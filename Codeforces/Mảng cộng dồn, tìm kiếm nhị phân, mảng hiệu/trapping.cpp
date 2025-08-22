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
const int N = 1e5 + 5;

int n, ans = 0, a[N], l[N], r[N];

main() {
	fast 
	cin >> n;
	For (i, 1, n) cin >> a[i];
	For (i, 1, n) l[i] = max(l[i - 1], a[i]);
	Ford (i, n, 1) r[i] = max(r[i + 1], a[i]);
	For (i, 1, n) ans += min(l[i], r[i]) - a[i];
	cout << ans;
	return 0;
}
 