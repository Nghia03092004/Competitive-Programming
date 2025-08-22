#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int n, tmp, ans = 0, a[12], flag[12];

bool nt(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return n > 1;
}

int Count(int n) {
	int res = 0;
	while (n) {
		n /= 10;
		res++;
	}
	return res;
}

void sol() {
	int cur = 0;
	for (int i = 1; i <= tmp; i++) {
		if (flag[i]) cur = cur * 10 + a[i];
	if (nt(cur)) ans = max(ans, cur);
	}
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		flag[i] = j;
		if (i == tmp) sol();
		else Try(i + 1);
	}
}

int main() {
	fast
	cin >> n;
	tmp = Count(n);
	for (int i = 1; i <= tmp; i++) {
		a[i] = n / pow(10, tmp - i);
		int res = pow(10, tmp - i);
		n %= res; 
	}
	Try(1);
	if (ans == 0) cout << -1;
	else cout << ans;
}