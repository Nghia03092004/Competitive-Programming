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
const int N = 1e6 + 5;

int n, p, a[N], pref[N];

int bs(int pos) {
	int l = 1, r = pos, res = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (a[pos] - pref[mid] >= p) {
			res = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return res;
}

main() {
	fast
	cin >> n >> p;
	pref[0] = 1e18;
	For (i, 1, n) {
		cin >> a[i];
		pref[i] = min(pref[i - 1], a[i]);
	}
	int a = 0, b = 0;
	For (i, 2, n) {
		int j = bs(i);
		if (j != -1)
			if (i - j > b - a) b = i, a = j;
	}
	if (a == 0 && b == 0) cout << 0;
	else cout << a << " " << b;
	return 0;
}
 