#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, P;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P;
	if (P > N/2) cout << (N - P);
	else cout << P/2;
}