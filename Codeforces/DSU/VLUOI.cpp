#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define st first
#define nd second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int inf = 1e18;
const int maxN = (int) 1e6 + 5;
int n, m;
int a[1005][1005];
int par[maxN], sz[maxN], dist[maxN], val[maxN];
vector<int> adj[maxN];
multiset<int, greater<int>> ms;


int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        if (ms.find(x) != ms.end()) ms.erase(ms.find(x));
        if (ms.find(y) != ms.end()) ms.erase(ms.find(y));
        par[y] = x;
        sz[x] += sz[y];
        ms.insert(x);
    }
}

int id(int x, int y) {
    return (x - 1) * m + y;
}

bool valid(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void dijk() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, acs(1)});
    dist[acs(1)] = 0;
    while (!pq.empty()) {
        int cost = pq.top().st;
        int u = pq.top().nd;
        pq.pop();
        if (cost > dist[u]) continue;
        for (int v: adj[u]) 
            if (val[v] == 1) {
                if (dist[v] > dist[u]) {
                    dist[v] = dist[u];
                    pq.push({dist[v], v});
                } 
            } else {
                    if (dist[v] > dist[u] + sz[v] * val[v]) {
                        dist[v] = dist[u] + sz[v] * val[v];
                        pq.push({dist[v], v});
                    }
                }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            val[id(i, j)] = a[i][j];
            dist[id(i, j)] = inf;
        }
    }
    for (int i = 1; i <= n * m; ++i) {
        sz[i] = 1;
        par[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (valid(x, y) && a[x][y] == a[i][j]) 
                    join(id(x, y), id(i, j));
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (valid(x, y) && a[x][y] != a[i][j]) {
                    adj[acs(id(i, j))].push_back(acs(id(x, y)));
                    adj[acs(id(x, y))].push_back(acs(id(i, j)));
                }
            }
        }
    }
    dijk();
    cout << dist[acs(id(n, m))];
}