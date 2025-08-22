#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1, M = 1e7 + 1;
bool prime[M];
int a[N], b[N];
deque<int> c;

void sieve() {
	for (int i = 1; i <= M; i++) prime[i] = true;
	prime[1] = false;
	for (int i = 2; i <= sqrt(M); i++) 
		if (prime[i]) 
			for (int j = i*i; j <= M; j += i) prime[j] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (prime[a[i]]) {
			b[++cnt] = a[i];
		}
	}
	if (cnt == 0) cout << -1;
	else {
		sort(b + 1, b + cnt + 1);
		c.push_back(b[cnt]);
		for (int i = cnt - 1; i >= 1; i -= 2) {
			c.push_front(b[i]);
			if (i > 1) c.push_back(b[i - 1]);
		}
		for (auto v: c) cout << v << " ";
	}
 // 2 5 17 23 53
}