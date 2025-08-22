#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;
int n, m;
vector<int> g[maxN];
int dist1[maxN], dist2[maxN];
queue<int> q;

void BFS(int start, int dist[]) {
    for (int i = 1; i <= n; ++i)
        dist[i] = 1e9;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    BFS(1, dist1);
    BFS(n, dist2);

    for (int i = 1; i <= n; ++i)
        if (dist1[i] != 1e9 && dist2[i] != 1e9)
            cout << dist1[i] + dist2[i] << ' ';
        else cout << -1 << ' ';
}