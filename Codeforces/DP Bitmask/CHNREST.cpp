#include<bits/stdc++.h>

using namespace std;

const int N = 6e4 + 5;
long long n, m;
long long a[40], pow3[50], f[40];
long long ok[40][40], dp[40][N];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; ++i) 
        cin >> a[i];
    
    pow3[0] = 1;
    for (int i = 1; i <= n; ++i) pow3[i] = pow3[i - 1] * 3;
    getline(cin, s);


    int num = 0;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        s = s + " ";
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] >= '0' && s[j] <= '9') 
                num = num * 10 + s[j] - 48;
            else {
                if (num != 0) 
                    ok[num - 1][i] = true;
                num = 0;
            }
        }
    }

    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < pow3[n]; ++j)
            dp[i][j] = 1e9;

    int res = 0;
    for (int i = 0; i < n; ++i) 
        if (ok[0][i])
            res += pow3[i];

    dp[0][res] = a[0];
    dp[0][0] = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < pow3[n]; ++j) 
            dp[i][j] = dp[i - 1][j];
        for (int j = 0; j < pow3[n]; ++j) {
            int k = j, tmp = 0;
            for (int x = n - 1; x >= 0; --x) 
                for (int y = 2; y >= 0; --y) 
                    if (k - pow3[x] * y >= 0) {
                        k -= (pow3[x] * y);
                        f[x] = y;
                        break;
                    }
            for (int x = 0; x < n; ++x) 
                if (ok[i][x]) {
                    f[x]--;
                    if (f[x] < 0)
                        goto l1;
                }

            for (int i = 0; i < n; ++i) 
                tmp += (pow3[i] * f[i]);
            dp[i][j] = min(dp[i][j], dp[i - 1][tmp] + a[i]);
            l1:;
        }
    }

    if (dp[m - 1][pow3[n] - 1] < 1e9) 
        cout << dp[m - 1][pow3[n] - 1] << '\n';
    else 
        cout << -1 << '\n';

}