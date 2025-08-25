#include<bits/stdc++.h>

using namespace std;

#define int long long
int k;
string L, R;
int mod = (int) 1e9 + 7;
int dp[105][2][2], way[105][2][2];

pair<int, int> f(string &num, int pos, int tight, int lead) {
    if (pos == 0)
        return {0, 1};
    if (dp[pos][tight][lead] != -1)
        return {dp[pos][tight][lead],  way[pos][tight][lead]};

    int limit = (tight == 1) ? (num[num.size() - pos] - '0') : 9;

    int ans = 0, ways = 0;
    for (int i = 0; i <= limit; ++i) {
        if (i == 0 & lead) {
            pair<int, int> x = f(num, pos - 1, 0, 1);
            ans += x.first;
            ways += x.second;
        } else {
            pair<int, int> x = f(num, pos - 1, (tight & (i == limit)), 0);
            ans += x.first + (i == k) * x.second;
            ways += x.second;
        }
        ans %= mod;
        ways %= mod; 
    }

    dp[pos][tight][lead] = ans;
    way[pos][tight][lead] = ways;

    return {ans, ways};
}

int g(string &num) {
    int ans = 0;
    for (auto v: num) 
        ans += ((v - '0') == k);
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> L >> R >> k;
    memset(dp, -1, sizeof dp);
    int ans_R = f(R, R.size(), 1, 1).first;
    memset(dp, -1, sizeof dp);
    int ans_L = f(L, L.size(), 1, 1).first;

    cout << ((ans_R - ans_L + g(L)) % mod + mod) % mod;
}