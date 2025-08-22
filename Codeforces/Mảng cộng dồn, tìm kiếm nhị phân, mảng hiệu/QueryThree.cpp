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

int n, k, a[N], pref[N];

main() {
	fast
	cin >> n >> k;
	For (i, 1, n) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	For (i, 1, n) {
		int l = 1, r = i, ans = -1;
		while (l <= r) {
			int mid = (l + r)/2;
			if (pref[i] - pref[mid - 1] <= k) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
 


// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 3;
// int n, a[N];
// long long k, pref[N];

// int find(int k, int l, int r) {
// 	int ans = -1, tmp = r;
// 	while (l <= r) {
// 		int mid = (l + r)/2;
// 		if (pref[tmp] - pref[mid - 1] <= k) {
// 			ans = mid;
// 			r = mid - 1;
// 		} else l = mid + 1;
// 	} 
// 	return ans;
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n >> k;
// 	for (int i = 1; i <= n; i++) {
// 		cin >> a[i];
// 		pref[i] = pref[i - 1] + a[i];
// 	}
// 	sort(a + 1, a + n + 1);
// 	for (int i = 1; i <= n; i++) {
// 		cout << find(k, 1, i) << endl;
// 	}
// }