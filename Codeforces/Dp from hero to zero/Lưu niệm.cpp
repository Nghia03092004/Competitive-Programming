#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxN = 1e3 + 5;
int n, k;
int a[maxN], b[maxN], f[maxN][1024 * 4 + 5];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    k *= 1024;
    for (int i =1 ; i <= n; ++i)
        cin >> a[i] >> b[i];
    f[0][0] = 0;
    for (int i = 1; i <= k; ++i)
        f[0][i] = -1e18;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            f[i][j] = f[i - 1][j];
            if (j - a[i] >= 0)
                f[i][j] = max(f[i][j], f[i][j - a[i]] + b[i]);
        }

    int ans = -1e18;
    for (int i = 1; i <= k; ++i)
        ans = max(ans, f[n][i]);

    cout << ans;
}


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 3;
const int K = 5e3 + 4;
int n, W;
int w[N];
long long v[N], dp[N][K]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> W;
    W = W * 1024;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    dp[1][0] = 0;
    for (int i = w[1]; i <= W; i++) dp[1][i] = dp[1][i - w[1]] + v[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j >= w[i]) 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
                else dp[i][j] = dp[i - 1][j];
            }
    }
    cout << dp[n][W];
    
}