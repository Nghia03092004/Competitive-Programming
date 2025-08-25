#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = (int) 1e9 + 7;
string L, R;
int dp[105][3], way[105][3];

pair<int, int> f(string &num, int pos, int tight) {
    if (pos == 0) 
        return {0, 1};

    if (dp[pos][tight] != -1) 
        return {dp[pos][tight], way[pos][tight]};

    int limit = (tight == 1) ? (num[num.size() - pos] - '0') : 9;

    int ans = 0;
    int ways = 0;
    for (int i = 0; i <= limit; ++i) {
        pair<int, int> x = f(num, pos - 1, (tight & (i == limit)));
        ans += (x.first + i * x.second);
        ways += x.second;
    }

    ans %= mod;
    ways %= mod;
    dp[pos][tight] = ans;
    way[pos][tight] = ways;

    return {ans, ways};
}


int g(string &L) {
    int res = 0;
    for (char x: L) 
        res += x - '0';
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> L >> R;

    memset(dp, -1, sizeof dp);
    int ans_R = f(R, R.size(), 1).first;
    memset(dp, -1, sizeof dp);
    int ans_L = f(L, L.size(), 1).first;

    cout << ((ans_R - ans_L + g(L)) % mod + mod) % mod;
}