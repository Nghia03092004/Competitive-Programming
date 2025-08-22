#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
const int maxN = 2e6 + 5; // maxa[i] = 1e6;
const int N = 5e3 + 5;
bool prime[maxN + 1];
int n;
int a[N];
pair <int, int> dp[N];

void sieve() {
    fill(prime + 1, prime + maxN + 1, true);
    prime[1] = false;
    for (int i = 2; i * i <= maxN; ++i)
        if (prime[i])
            for (int j = i * i; j <= maxN; j += i)
                prime[j] = false;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[i].fi = 1;
        dp[i].se = a[i];
    }

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; j++)
            if (prime[a[i] + dp[j].se]) {
                dp[i].fi = max(dp[i].fi, dp[j].fi + 1);
                dp[i].se = a[i];
            }

    int ans = -1e18;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i].fi);
    cout << ans;
    return 0;
}