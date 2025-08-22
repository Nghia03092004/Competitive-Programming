#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;
int n, m;
vector<int> g[maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        cout << g[i].size() << ' ';
        sort(g[i].begin(), g[i].end());
        for (auto v: g[i]) cout << v << ' ';
        cout << '\n';
    }
}