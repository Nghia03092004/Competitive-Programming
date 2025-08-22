#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;
int n, k;
vector<int> g[maxN];
queue<int> q;
int dist[maxN];
vector<int> ans;

void BFS(int start) {
    for (int i = 1; i <= n; ++i) dist[i] = 1e9;
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

    cin >> n >> k;
    for (int u = 1; u <= n; ++u) {
        int m; cin >> m;
        for (int i = 1, v; i <= m; ++i) {
            cin >> v;
            g[u].push_back(v);
        }
    }

    BFS(k);

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != 1e9) {
            ++cnt;
            ans.push_back(i);
        }
    }
    cout << cnt << '\n';
    for (auto v: ans) cout << v << ' ';
}