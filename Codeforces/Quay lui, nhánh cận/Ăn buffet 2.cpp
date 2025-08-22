#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair <int, int>
#define w first
#define v second 
const int N = 35;
int n, U, V, ans = 0;
int Weight[N], Value[N];
ii a[N];

bool cmp(ii a, ii b) {
	return a.w > b.w;
}

void Try(int i, int W, int val) {
	if (W > V || W + Weight[i] < U || val + Value[i] < ans) return;
	if (i <= n) 
		for (int j = 0; j <= 1; j++) {
			if (!j) Try(i + 1, W, val);
			else Try(i + 1, W + a[i].w, val + a[i].v); 
		} 
	else ans = max(ans, val);
}   

main() {
	fast
	cin >> n >> U >> V;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].w >> a[i].v;
	sort(a + 1, a + n + 1, cmp);
	Weight[n] = a[n].w, Value[n] = a[n].v;
	for (int i = n - 1; i >= 1; i--) {
		Weight[i] = Weight[i + 1] + a[i].w;
		Value[i] = Value[i + 1] + a[i].v;
	}
	Try(1, 0, 0);
	cout << ans;
}