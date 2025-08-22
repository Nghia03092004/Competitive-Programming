#include<bits/stdc++.h>
using namespace std;

int n;
long long dp[70][4];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][1];
	}
	cout << dp[n][0] + dp[n][1] + dp[n][2];
	return 0;
}


#include<bits/stdc++.h>
using namespace std;

//dp[i] la so cach xep thoa man dieu kien

typedef long long ll;
const int N = 70;
int n;
ll dp[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 7;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	cout << dp[n];
}