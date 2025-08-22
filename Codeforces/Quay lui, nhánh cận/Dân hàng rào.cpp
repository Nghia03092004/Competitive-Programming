#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e3 + 4;
int n, ans = 0, a[N];

void Try(int l, int r) {
	ans++;
	if (l == r) return;
	int x = *min_element(a + l, a + r + 1);
	for (int i = l; i <= r; i++) {
		if (a[i] != x) {
			int pos = i;
			while (i <= r && a[i] != x) i++;
			i--;
			Try(pos, i);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	Try(1, n);
	cout << ans;
}