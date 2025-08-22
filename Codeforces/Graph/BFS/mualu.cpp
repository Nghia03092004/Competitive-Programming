#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;
int n, m, x;
vector<int> g[maxN];
bool vis[maxN];

void DFS(int i) {
    for (auto x: g[i]) {
        if (!vis[x]) {
            vis[x] = true;
            DFS(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> x;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w >= x) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        if (!vis[i]) DFS(i), ++ans;

    cout << ans;
}s