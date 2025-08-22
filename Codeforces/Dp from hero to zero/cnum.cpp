#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int n, a[N], dp[N][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + (a[i] != 1);
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (a[i] != 2);
	}
	cout << min(dp[n][1], dp[n][2]);
}
/*
dp[i][j]: là số thao tác thực hiện ích nhất để biến dãy đã cho thành một dãy 
không giảm với i thằng đầu và giá trị của thằng a[i] = j;

dp[i][1]: chắc chắn a[i] kết thúc tại 1

còn i - 1 thằng, tạo thành dãy không giảm a[i - 1] = 1;
if (a[i] == 1)
	dp[i][1] = dp[i - 1][1];
else 
	dp[i][1] = dp[i - 1][1] + 1;

dp[i][2]: chắc chắn a[i] kết thúc tại 2 
còn i - 1 thằng, tạo thành dãy không giảm a[i - 1] = 2;
hoặc a[i - 1] = 1;

if (a[i] == 1)
	dp[i][1] = min(dp[i - 1][1], dp[i - 2][2]) + 1;
esle 
	dp[i][1] = min(dp[i - 1][1], dp[i - 2][2]);
min(dp[n][1], dp[n][2]);
dp[0][1] = dp[0][2] = 0;
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, a[N], dp[N][3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + 1;
		} else {
			dp[i][1] = dp[i - 1][1] + 1;
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
		}
	} 
	cout << min(dp[n][1], dp[n][2]);
	return 0;
}