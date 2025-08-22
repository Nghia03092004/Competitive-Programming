#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e5 + 5;
const int MASK = 30;
int n, mod = 1e9 + 7;
int dp[maxN][MASK];
int pow3[5];

vector<int> get(int mask) {
    vector<int> ret;
    for (int i = 2; i >= 0; --i) {
        for (int j = 2; j >= 0; --j) {
            if (mask - j * pow3[i] >= 0) {
                mask -= j * pow3[i];
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
    return (bit[0] != bit[1] && bit[1] != bit[2]);
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
    pow3[0] = 1;
    pow3[1] = 3;
    pow3[2] = 9;
    
    cin >> n;
    vector<int> goodmask;
    for (int mask = 0; mask < 27; ++mask) 
        if (valid(get(mask))) 
            goodmask.push_back(mask);

    vector<int> matchmask[30];
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



// #include<bits/stdc++.h>

// using namespace std;

// const int maxN = (int) 1e5 + 5;
// const int mod = (int) 1e9 + 7;
// int n; 
// long long f1[maxN], f2[maxN];

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);

//     cin >> n;
//     f1[1] = 6;
//     f2[1] = 6;
//     for (int i = 2; i <= n; ++i) {
//         f1[i] = (3ll * f1[i - 1] + 2ll * f2[i - 1]) % mod;
//         f2[i] = (2ll * f1[i - 1] + 2ll * f2[i - 1]) % mod;
//     }
//     cout << (f1[n] + f2[n]) % mod;
// }