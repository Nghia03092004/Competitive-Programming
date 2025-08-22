#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

int n;
int a[N], dp[N][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1][0] = a[1];
	dp[1][1] = -1e9;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max({dp[i - 1][0], dp[i - 1][1] + a[i], a[i]});
		dp[i][1] = max({dp[i - 1][1], dp[i - 1][0] - a[i]});
	}
	cout << max(dp[n][0], dp[n][1]);
}

/*
dp[i]: la suc manh cua day con lon nhat voi i phan tu dau
j = 0: day con ket thuc boi dau +
j = 1: day con ket thuc boi dau -
dp[i][j]

dp[i][0]

1> khong lay i
i - 1 thang, ket thuc boi dau +
dp[i - 1][0]

2> lay i, chac chan i phai dau +
i - 1 thang, ket thuc voi dau -
dp[i - 1][1] + a[i]

3> lay moi i: a[i]

dp[i][0] = max({dp[i - 1][0], dp[i - 1][1] + a[i], a[i]})

dp[i][1]: day co suc manh lon nhat va ket thuc bang dau tru

1> khong lay i
i - 1 thang, ket thuc voi dau -
dp[i - 1][1]
2> lay i , chac chan i phai la dau -
i - 1 thang, ket thuc boi dau +
dp[i - 1][0] - a[i];
3> khong co truong hop nay vi dãy bắt đầu bằng dấu cộng

dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i])

dp[1][0] = a[1];
dp[1][1] = -1e9(vo nghia)

ans = max(dp[n][0], dp[n][1])
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, ans = -1e9, a[N], dp[N][N];

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			if (j % 2 == 0) 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - a[i]);
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
	for (int i = 1; i <= n; i++) 
		ans = max(ans, dp[n][i]);
	cout << ans;
}