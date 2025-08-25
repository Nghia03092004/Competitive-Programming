#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = (int) 1e9 + 7;

string L, R;
int k, p;
int dp[105][105][2][2];

int f(string &num, int pos, int rem_p, int tight, int lead) {
    if (rem_p < 0)
        return 0;

    if (pos == 0)
        return 1;

    if (dp[pos][rem_p][tight][lead] != -1)
        return dp[pos][rem_p][tight][lead];

    int limit = (tight == 1) ? (num[num.size() - pos] - '0') : 9;

    int res = 0;
    for (int i = 0; i <= limit; ++i) {
        if (i == 0 && lead) 
            res += f(num, pos - 1, rem_p, 0, 1);
        else 
            res += f(num, pos - 1, rem_p - (i == p), (tight & (i == limit)), 0); 
    }

    res %= mod;
    dp[pos][rem_p][tight][lead] = res;

    return res;
}

int g(string &num) {
    int cnt = 0;
    for (auto v: num) 
        cnt += ((v - '0') == p);
    return cnt <= k; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> L >> R >> k >> p;
    memset(dp, -1, sizeof dp);
    int ans_R = f(R, R.size(), k, 1, 1);
    memset(dp, -1, sizeof dp);
    int ans_L = f(L, L.size(), k, 1, 1);

    cout << ((ans_R - ans_L + g(L)) % mod + mod) % mod;
}