#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
int n, a, b, c;
int arr[N];
long long dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i)
        if (arr[i] == 0) dp[i] = dp[i - 1];
        else dp[i] = min({dp[i - 1] + a, dp[max(0, i - 7)] + b, dp[max(0, i - 30)] + c});

    cout << dp[n];
}