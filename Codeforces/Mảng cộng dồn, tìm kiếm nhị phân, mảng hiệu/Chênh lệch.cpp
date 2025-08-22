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
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n, q, a[N], pref[N];

int bs(int a, int b) {
	int l = a, r = b, res = a - 1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (pref[mid] - pref[a - 1] <= pref[b] - pref[mid]) {
			res = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	return res;
}

main() {
	fast
	cin >> n >> q;
	For (i, 1, n) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		int pos = bs(u, v);
		cout << min((pref[v] - pref[pos]) - (pref[pos] - pref[u - 1]), (pref[pos + 1] - pref[u - 1]) - (pref[v] - pref[pos + 1])) << endl;
	}
	return 0;
}

 