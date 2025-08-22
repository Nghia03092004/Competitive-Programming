#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e3 + 5;
const int MASK = (int) 3125 + 5;
int n, mod = 1e9 + 7;
int dp[maxN][MASK];
int pow5[7];

vector<int> get(int mask) {
    vector<int> ret;
    for (int i = 4; i >= 0; --i) {
        for (int j = 4; j >= 0; --j) {
            if (mask - j * pow5[i] >= 0) {
                mask -= j * pow5[i];
                ret.push_back(j);
                break;
            }
        }
    }

    // for (auto bit: ret)
    //     cout << bit << " ";

    return ret;
}

bool valid(vector <int> bit) {
    return (bit[0] != bit[1] && bit[1] != bit[2] && 
        bit[2] != bit[3] && bit[3] != bit[4]);
}

bool check(vector<int> bit1, vector<int> bit2) {
    for (int i = 0; i < bit1.size(); ++i) 
        if (bit1[i] == bit2[i])
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pow5[0] = 1;
    pow5[1] = 5;
    pow5[2] = 25;
    pow5[3] = 125;
    pow5[4] = 625;

    cin >> n;
    vector<int> goodmask;
    for (int mask = 0; mask < 3125; ++mask) 
        if (valid(get(mask))) 
            goodmask.push_back(mask);

    vector<int> matchmask[MASK];
    for (auto mask: goodmask) // row i
        for (auto premask: goodmask) // row i - 1
            if (check(get(mask), get(premask)))
                matchmask[mask].push_back(premask);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto mask: goodmask) {
            if (i == 1) 
                dp[i][mask] = 1;
            else {
                for (auto premask: matchmask[mask]) 
                    dp[i][mask] = (dp[i][mask] + dp[i - 1][premask]) % mod;
            }
            if (i == n)
                ans = (ans + dp[i][mask]) % mod;
        }
    }

    cout << ans;
}