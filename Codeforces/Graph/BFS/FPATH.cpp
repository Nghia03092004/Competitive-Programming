#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

const int maxN = 1e5 + 5;
int n, m;
vector<ii> g[maxN];
queue<int> q;
int dist[maxN];

bool BFS(int mid) {
    for (int i = 1; i <= n; ++i) dist[i] = 1e9;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: g[u]) {
            if (dist[v.first] > dist[u] + 1 && v.second > mid) {
                dist[v.first] = dist[u] + 1;
                q.push(v.first);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        if (dist[i] == 1e9)
            return false;
    return true;
}

void solve() {
    int ans = 0;
    int l = 1, r = maxN, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (!BFS(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    if (!BFS(0)) cout << -1;
    else solve();
}