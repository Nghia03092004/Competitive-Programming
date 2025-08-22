#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int a[N];
int l, r, cnt = 0, ans = 0;

void sieve() {
	for (int i = 2; i <= N; i++) 
		a[++cnt] = i*i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> l >> r;
	for (int i = l; i <= r - 1; i++) {
		for (int j = i + 1; j <= r; j++) {
			for (int k = 1; k <= cnt; k++) {
				if (a[k] > i*j) break;
				if ((i*j) % a[k] == 0) {
					++ans;
					break;
				}
			}
		}
	}
	cout << ans;
} 