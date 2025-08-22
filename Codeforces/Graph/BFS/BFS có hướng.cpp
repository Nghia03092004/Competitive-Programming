#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 5;
int n, m, s, t;
int dist[maxN];
vector<int> g[maxN];
queue<int> q;

void BFS(int start) {
    for (int i = 1; i <= n; ++i) dist[i] = 1e9;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
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

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    BFS(s);

    cout << (dist[t] == 1e9 ? -1 : dist[t]);
}