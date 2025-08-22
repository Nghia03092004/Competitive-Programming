#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5 + 5;
int n;
int sz[maxN], ans[maxN];
vector <int> g[maxN];
bool vis[maxN];

void BFS(int u) {
    vis[u] = true;
    ++ans[u];
    for (int v: g[u]) {
        if (vis[v] == false) {
            BFS(v);
            sz[u] += sz[v];
            ans[u] = ans[u] + ans[v] + sz[v];
            vis[v] = true;
        }
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int u;
        cin >> u;
        g[u].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i) sz[i] = 1;
    BFS(1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}