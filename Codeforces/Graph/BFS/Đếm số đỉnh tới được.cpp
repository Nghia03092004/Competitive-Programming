#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;
int n, m, s;
int dist[maxN];
vector<int> g[maxN];
queue<int> q;

void BFS(int start) {
    for (int i = 1; i <= n; ++i) dist[i] = 1e9;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())  {
        int u = q.front();
        q.pop();
        for (auto v: g[u]) 
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    BFS(s);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != 1e9) ++ans;
    }

    cout << ans;
}