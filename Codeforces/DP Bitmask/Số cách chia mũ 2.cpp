#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 17;
const int M = 51;
const int MASK = (1 << 16);
const int mod = 1e9 + 7;
int n, m;
bool hat[M][N];
int dp[M][MASK];
vector<int> ones[MASK];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int sz; cin >> sz;
        for (int j = 1; j <= sz; ++j) {
            int x; cin >> x;
            hat[x][i] = 1; // mu x cho nguoi i
        } 
    }

    for (int mask = 0; mask < (1 << n); ++mask) 
        for (int i = 0; i < n; ++i) 
            if ((mask >> i) & 1) 
                ones[mask].push_back(i);

    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            dp[i][mask] = dp[i - 1][mask];
            for (auto bit: ones[mask]) 
                if (hat[i][bit + 1])
                    dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ (1 << bit)]) % mod; 
        }
    }

    cout << dp[m][(1 << n) - 1]; // O(m * 2^n * n)
}