#include<bits/stdc++.h>

using namespace std;

const int maxN = 5e4 + 5;
int n, m, k;
int dist1[maxN], dist2[maxN];
vector<int> a[maxN], b[maxN];
int cnt[maxN];
queue<int> q;

void bfs(int start, int finish,int dist[], vector<int> g[]) {
    for (int i = 1; i <= n; ++i)
        dist[i] = 1e9;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        ++cnt[u];
        q.pop();
        for (auto v: g[u]) {
            if (v != finish && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    while (m--) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        b[v].push_back(u);
    }

    for (int i = 1; i <= k; ++i) {
        int u, v; cin >> u >> v;
        bfs(u, v, dist1, a); cnt[v]++;
        bfs(v, u, dist2, b); cnt[u]++;
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 2 * k)
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto x: ans)
        cout << x << ' ';
}