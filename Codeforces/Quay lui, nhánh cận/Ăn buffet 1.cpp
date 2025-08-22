#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair <int, int>
#define w first
#define v second
const int N = 20;
int n, U, V, W = 0, val= 0, ans = 0;
ii a[N];

void Try(int i) {
	if (i > n) {
		if (W >= U && W <= V) ans = max(ans, val);
	} else for (int j = 0; j <= 1; j++) {
		if (j == 1) {
			W += a[i].w;
			val += a[i].v;
			Try(i + 1);
			W -= a[i].w;
			val -= a[i].v;
		} else Try(i + 1);
	}
}

main() {
	fast
	cin >> n >> U >> V;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].w >> a[i].v;
	Try(1);
	cout << ans;
}