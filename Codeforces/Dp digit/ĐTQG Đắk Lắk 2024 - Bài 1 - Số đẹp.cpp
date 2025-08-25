#include <bits/stdc++.h>
using namespace std;

#define int long long
string L, R;
int dp[20][10][2]; // pos, last, lead

int f(string &num, int pos, int last, int lead, bool tight) {
    if (pos == 0) return 1;

    if (!tight && dp[pos][last][lead] != -1)
        return dp[pos][last][lead];

    int limit = tight ? (num[num.size() - pos] - '0') : 9;
    int res = 0;

    for (int i = 0; i <= limit; ++i) {
        if (lead && i == 0) {
            // Vẫn ở trạng thái leading zero
            res += f(num, pos - 1, last, 1, tight && (i == limit));
        } else {
            if (i == last) continue; // Không cho 2 số giống nhau liền kề
            res += f(num, pos - 1, i, 0, tight && (i == limit));
        }
    }

    if (!tight) dp[pos][last][lead] = res;
    return res;
}

int solve(string &num) {
    return f(num, num.size(), 0, 1, 1);
}

int g(string &num) {
    for (int i = 0; i < (int)num.size() - 1; ++i)
        if (num[i] == num[i + 1]) return 0;
    return 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);

    memset(dp, -1, sizeof(dp));

    int t;
    cin >> t;
    while (t--) {
        cin >> L >> R;
        cout << solve(R) - solve(L) + g(L) << '\n';
    }
}