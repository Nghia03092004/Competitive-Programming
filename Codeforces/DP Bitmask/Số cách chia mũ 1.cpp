#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 21;
const int MASK = (1 << 20);
const int mod = 1e9 + 7;
int n;
bool a[N][N];
int dp[N][MASK];
vector<int> len[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int mask = 0; mask < (1 << n); ++mask) 
        len[__builtin_popcount(mask)].push_back(mask);

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (auto mask: len[i]) {
            vector<int> ones;
            for (int j = 0; j < n; ++j) 
                if ((mask >> j) & 1)
                    ones.push_back(j);

            for (auto bit: ones) 
                if (a[i][bit + 1]) 
                    dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ (1 << bit)]) % mod;
        }
    }

    cout << dp[n][(1 << n) - 1];
}