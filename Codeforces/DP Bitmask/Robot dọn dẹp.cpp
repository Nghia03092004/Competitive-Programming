#include<bits/stdc++.h>

using namespace std;

#define int long long
#define st first
#define nd second
#define ii pair<int, int>

const int N = 17;
const int MASK = (1 << 16) + 5;
int n, m, r;
int c[N][N], dist[N][N];
char f[N][N];
int dp[N][MASK];
ii v[N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(int i) {
    queue<ii> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dist[i][j] = 1e9;
    q.push({v[i].st, v[i].nd});
    dist[v[i].st][v[i].nd] = 0;
    while (!q.empty()) {
        int u = q.front().st;
        int v = q.front().nd;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int x = u + dx[dir];
            int y = v + dy[dir];
            if (x > 0 && x <= n && y > 0 && y <= m 
                && f[x][y] != 'x' && dist[x][y] > dist[u][v] + 1) {
                dist[x][y] = dist[u][v] + 1;
                q.push({x, y});
            }
        }
    }

    for (int j = 0; j <= r; ++j) 
        c[i][j] = dist[v[j].st][v[j].nd];
}

string np(int mask) {
    string s = "";
    for (int j = r; j >= 0; --j) 
        if ((mask >> j) & 1) 
            s.push_back('1');
        else 
            s.push_back('0');
    return s;
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> m >> n) {
        if (n == 0 && m == 0) break;
        r = 0;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) {
                cin >> f[i][j];
                if (f[i][j] == 'o') 
                    v[0] = {i, j};
                else if (f[i][j] == '*') 
                    v[++r] = {i, j};
            }

        for (int i = 0; i <= r; ++i)
            BFS(i);

        for (int i = 0; i <= r; ++i) 
            for (int mask = 0; mask < (1 << (r + 1)); ++mask)
                dp[i][mask] = 1e9;

        dp[0][1] = 0;
        int ans = 1e9;

        for (int mask = 2; mask < (1 << (r + 1)); ++mask) {
            vector<int> ones;
            for (int j = 0; j <= r; ++j) 
                if ((mask >> j) & 1) 
                    ones.push_back(j);

            for (auto i: ones) {
                for (auto j: ones) {
                    if (i != j) 
                        dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + c[j][i]);
                }
            }
        }

        for (int i = 0; i <= r; ++i) 
            ans = min(ans, dp[i][(1 << (r + 1)) - 1]);
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}