#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>

using namespace std;

#define int long long
const int MAX_N = 3e5 + 5;
const int MAX_VAL = 1e6 + 5;

int lp[MAX_VAL];
int n, m;
int a[MAX_N];
int st[MAX_N << 2];
set<int> s;
vector<int> eraseList;

int numDivisor(int x) {
	int res = 1;
	while (x > 1) {
		int k = lp[x], cnt = 0;
		while (x % k == 0) {
			++cnt;
			x /= k;
		}
		res *= cnt + 1;
	}
	return res;
} 

void update(int id, int l, int r, int i, int val) {
	if (i > r || i < l) return;
	
	if (l == r) {
		st[id] += val;
		return;
	}
	
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, i, val);
	update(id << 1|1, mid + 1, r, i, val);
	
	st[id] = st[id << 1] + st[id << 1|1];
}

int get(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return 0;
	
	if (l >= u && r <= v) return st[id];
	
	int mid = (l + r) >> 1;
	return get(id << 1, l, mid, u, v) + get(id << 1| 1, mid + 1, r, u, v);
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 2; i * i < MAX_VAL; i++) {
		if (!lp[i]) {
			for (int j = i * i; j < MAX_VAL; j += i) {
				lp[j] = i;
			}
		}
	}
	
	for (int i = 2; i < MAX_VAL; i++) {
		if (!lp[i]) lp[i] = i;
	}
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(i);
		update(1, 1, n, i, a[i]);
	}
	
	while (m--) {
		int t, l, r;
		cin >> t >> l >> r;
		
		if (t == 1) {
			auto it = s.lower_bound(l);
			eraseList.clear();
			while (it != s.end() && *it <= r) {
				int tmp = numDivisor(a[*it]);
				if (tmp == a[*it]) {
					eraseList.push_back(*it);
				} else {
					update(1, 1, n, *it, -a[*it] + tmp);
					a[*it] = tmp;
				}
				it++;
			} 
			for (auto i : eraseList) s.erase(i);
		}
		else cout << get(1, 1, n, l, r) << '\n';
	}
}