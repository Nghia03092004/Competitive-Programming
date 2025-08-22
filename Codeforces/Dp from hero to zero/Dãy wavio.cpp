#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
long long a[N];
int xuoi[N], nguoc[N];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) xuoi[i] = max(xuoi[i], xuoi[j] + 1);
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) nguoc[i] = max(nguoc[i], nguoc[j] + 1);
		} 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, min(xuoi[i], nguoc[i])*2);
	} 
	cout << ans + 1;
}


// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// const int N = 1e3 + 4;
// int n, ans = 0, a[N], l[N], r[N];

// main() {
// 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	cin >> n;
// 	for (int i = 1; i <= n; i++) cin >> a[i];
// 	for (int i = 1; i <= n; i++) {
// 		l[i] = 1;
// 		for (int j = 1; j < i; j++) 
// 			if (a[j] < a[i]) l[i] = max(l[i], l[j] + 1);
// 	}
// 	for (int i = n; i >= 1; i--) {
// 		r[i] = 1;
// 		for (int j = i + 1; j <= n; j++)
// 			if (a[j] < a[i]) r[i] = max(r[i], r[j] + 1);
// 	}
// 	for (int i = 1; i <= n; i++) 
// 		ans = max(ans, min(l[i], r[i])*2 - 1);
// 	cout << ans;
// }


// #pragma GCC optimize("Ofast,fast-math")
// #pragma target("av2")
// #include<bits/stdc++.h>
// #define ii pair<int, int>
// #define st first
// #define nd second

// using namespace std;

// const int N = 1e5 + 5;
// int n, ans = 0;
// ii a[N];
// int b[N], pref[N], suff[N];
// int st[N << 2];


// void update(int id, int l, int r, int i, int val) {
// 	if (i < l || i > r) return;
	 
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

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);
	
// 	cin >> n;
// 	for (int i = 1; i <= n; i++) {
// 		cin >> a[i].st;
// 		a[i].nd = i;
// 	}
	
// 	sort(a + 1, a + n + 1);
	
// 	int id = 0;
// 	for (int i = 1; i <= n; i++) {
// 		if (a[i].st != a[i - 1].st) ++id;
// 		b[a[i].nd] = id;
// 	} 
	
// 	for (int i = 1; i <= n; i++) {
// 		pref[i] = get(1, 1, n, 1, b[i] - 1) + 1;
// 		update(1, 1, n, b[i], pref[i]);
// 	}
	
// 	memset(st, 0, sizeof st);
	
// 	for (int i = n; i >= 1; i--) {
// 		suff[i] = get(1, 1, n, 1, b[i] - 1) + 1;
// 		update(1, 1, n, b[i], suff[i]);
// 	}
	
// 	for (int i = 1; i <= n; i++) {
// 		ans = max(ans, min(pref[i], suff[i]) * 2 - 1);
// 	}
	
// 	cout << ans;
// 	return 0;
// }