#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair <int, int>
const int N = 1e6 + 7;
const int M = 1e4 + 3;
vector <int> prime;
vector <ii> pt;
int n, a[M], ans = 1;
bool Isprime[N];
const int mod = 1e9 + 7;

void sieve() {
	for (int i = 1; i <= N; i++) Isprime[i] = true;
	Isprime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) 
		if (Isprime[i])
			for (int j = i*i; j <= N; j += i) Isprime[j] = false;
	for (int i = 1; i <= N; i++) 
		if (Isprime[i]) prime.push_back(i);
}

void Analyze(int n) {
	for (int i: prime) {
		if (i*i > n) break;
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			pt.push_back({i, cnt});
		}
	}
	if (n > 1) pt.push_back({n, 1});
}

void Power(int radix, int ex) {
	for (int i = 1; i <= ex; i++) {
		ans = (ans * radix) % mod;
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Analyze(a[i]);
	}
	sort(pt.begin(), pt.end());
	for (int i = 0; i < pt.size(); i++) {
		if (pt[i].first != pt[i + 1].first) 
			Power(pt[i].first, pt[i].second);
	}
	cout << ans;
}
// small town boy in a big arcade