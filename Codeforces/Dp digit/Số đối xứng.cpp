#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int mod = (int) 1e9 + 7;

string L, R;
int len = 0;
int digits[105], config[105];
int dp[105][2][105];

int f(int pos, int tight, int lead) {
    if (pos > len) 
        return lead <= len;

    if (dp[pos][tight][lead] != -1) 
        return dp[pos][tight][lead];

    int limit = tight ? 9 : digits[pos], res = 0;
    for (int num = 0; num <= limit; ++num) {
        bool isSmaller = tight | (num < digits[pos]);
        if (num == 0 && pos == lead) 
            res = (res + f(pos + 1, isSmaller, lead + 1)) % mod;
        else {
            config[pos] = num;
            if (pos < lead + (len - lead + 1) / 2) 
                res = (res + f(pos + 1, isSmaller, lead)) % mod;
            else {
                if (config[pos] == config[len - pos + lead]) 
                    res = (res + f(pos + 1, isSmaller, lead)) % mod;
            }
        }
    }

    return dp[pos][tight][lead] = res;
}

int solve(string &num) {
    len = 0;
    for (char c: num) 
        digits[++len] = c - '0';
    
    memset(dp, -1, sizeof dp);
    return f(1, 0, 1);
}

int g(string &num) {
    int sz = num.size();
    for (int i = 0; i < sz; ++i) 
        if (num[i] != num[sz - i - 1]) 
            return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> L >> R;
    cout << ((solve(R) - solve(L) + g(L)) % mod + mod) % mod;
}