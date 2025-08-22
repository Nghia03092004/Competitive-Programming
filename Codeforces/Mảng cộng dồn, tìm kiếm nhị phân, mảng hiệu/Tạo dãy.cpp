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

int n, a[N], b[N], ma[N], ans = 0;

main() {
	fast
	cin >> n;
	For (i, 1, n) cin >> a[i], ma[i] = max(ma[i - 1], a[i]);
	For (i, 1, n) cin >> b[i]; 
	For (i, 1, n) {
		ans = max(ans, ma[i]*b[i]);
		cout << ans << endl;
	}
	return 0;
}