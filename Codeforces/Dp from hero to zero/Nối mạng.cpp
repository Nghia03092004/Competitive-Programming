#include<bits/stdc++.h>
using namespace std;


const int N  = 1e5 + 9;
long long a[N], dp[N]; 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a[i];
	}
	dp[1] = 1e9;
	dp[2] = a[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 2], dp[i - 1]) + a[i - 1];
 	}
   	cout << dp[n];
}

 