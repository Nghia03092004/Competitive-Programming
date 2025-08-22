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
#define rall(x) ((x).rbegin(), (x).rend)
typedef vector<int> vi;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n, m, a[N];

int f(int mid) {
	int sum = 0;
	for (auto x: a) sum += x/mid + (x % mid != 0);
	return sum;
}

int bs() {
	int l = 1, r = 1e18, res = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (f(mid) <= n) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

main() {
	fast
	cin >> n >> m;
	For (i, 1, m) cin >> a[i];
	cout << bs();
	return 0;
}
