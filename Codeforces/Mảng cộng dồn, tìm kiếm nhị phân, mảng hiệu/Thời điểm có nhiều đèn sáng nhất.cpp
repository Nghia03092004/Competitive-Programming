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

int n, a[N], cnt = 0;

main() {
	fast
	cin >> n;
	while (n--) {
		int s, t;
		cin >> s >> t;
		a[s]++, a[t + 1]--;
	}
	For (i, 1, N) a[i] += a[i - 1];
	int ans = *max_element(a + 1, a + N + 1);
	For (i, 1, N) 
		if (a[i] == ans) ++cnt;
	cout << ans << endl << cnt;
 	return 0;
}
 