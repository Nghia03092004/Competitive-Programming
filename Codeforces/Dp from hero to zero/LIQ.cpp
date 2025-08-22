#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 5;
int n, ans = 0;
int a[N], dp[N];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) 
			if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n"; 
}


// #pragma GCC optimize("Ofast,fast-math")
// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// int n;
// pair <int, int> a[N];
// int b[N], dp[N], st[4 * N];

// void update(int id, int l, int r, int i, int val) {
// 	if (i > r || i < l) return;
	
// 	if (l == r) {
// 		st[id] = max(st[id], val);
// 		return;
// 	}
	
// 	int mid = (l + r) >> 1;
// 	update(id << 1, l, mid, i, val);
// 	update(id << 1|1, mid + 1, r, i, val);
	
// 	st[id] = max(st[id << 1], st[id << 1|1]);
// }

// int get(int id, int l, int r, int u, int v) {
// 	if (l > v || r < u) return 0;
	
// 	if (l >= u && r <= v) return st[id];
	
// 	int mid = (l + r) >> 1;
// 	return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v)); 
// } 

// main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);
	
// 	cin >> n;
// 	for (int i = 1; i <= n; i++) {
// 		cin >> a[i].first;
// 		a[i].second = i;
// 	}
	
// 	sort(a + 1, a + n + 1);
	
// 	int id = 0;
// 	for (int i = 1; i <= n; i++) {
// 		if (a[i].first != a[i - 1].first) id++;
// 		b[a[i].second] = id;
// 	}
	
// 	int ans = 0;
// 	for (int i = 1; i <= n; i++) {
// 		dp[i] = get(1, 1, n, 1, b[i]) + 1;
// 		ans = max(ans, dp[i]);
// 		update(1, 1, n, b[i], dp[i]);
// 	}
	
// 	cout << ans;
// 	return 0;
// }


// #pragma GCC optimize("Ofast,fast-math")
// #include<bits/stdc++.h>

// using namespace std;

// void compress(vector<int> &a) {
// 	set <int> s(a.begin(), a.end());
// 	vector<int> b(s.begin(), s.end());
// 	for (int &x: a) {
// 		x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
// 	}
// }

// struct Fenwick {
// 	int n;
// 	vector<int> f;
	
// 	Fenwick(int n): n(n), f(n + 1, 0) {}
	
// 	void set(int x, int i) {
// 		for (; i <= n; i += i & (-i)) f[i] = max(f[i], x);
// 	}
	
// 	int get(int i) const {
// 		int r = 0;
// 		for (; i >= 1; i -= i & (-i)) r = max(r, f[i]);
// 		return r;
// 	}
// };

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);
	
// 	int n;
// 	cin >> n;
// 	vector<int> a(n);
// 	for (int &x: a) cin >> x;
	
// 	compress(a);
	
// 	Fenwick bit(n);
// 	for (int x: a) bit.set(bit.get(x - 1) + 1, x);
	
// 	cout << bit.get(n);
	
// 	return 0;
// }


// #include<iostream>
// #include<vector>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int n;
//     cin >> n;
//     vector <int> a(n);
//     for (int &x: a) cin >> x;

//     vector<int> f(n);
//     int result = 1;
//     for (int i = 0; i < n; ++i) {
//         f[i] = 0;
//         for (int j = i - 1; j >= 0; --j)
//             if (a[i] > a[j]) f[i] = max(f[i], f[j]);
//         ++f[i];
//         result = max(result, f[i]);
//     }

//     cout << result;
// }


// #include<bits/stdc++.h>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int &x: a) cin >> x;

//     vector<int> b(n + 1, INT_MAX);
//     b[0] = INT_MIN;
//     int ans = 1;
//     for (int x: a) {
//         int k = lower_bound(b.begin(), b.end(), x) - b.begin();
//         b[k] = x;
//         ans = max(ans, k);
//     }

//     cout << ans;
//     return 0;
// }