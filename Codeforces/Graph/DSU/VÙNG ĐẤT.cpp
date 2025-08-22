#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int> 
#define iii pair<int, ii>
#define st first
#define nd second

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int maxN = (int) 2e6 + 5;
int n, m, q, scc;
int par[maxN], sz[maxN];
bool check[maxN];
iii a[maxN];
ii query[maxN];
int ans[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);

    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        --scc;
    }
}

int water(int x, int y) {
    return (x - 1) * m + y;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            a[water(i, j)] = {x, {i, j}};
            par[water(i, j)] = water(i, j);
            sz[water(i, j)] = 1;
        }
    }

    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> query[i].st;
        query[i].nd = i;
    }

    sort(a + 1, a + n * m + 1, greater<iii> ());
    sort(query + 1, query + q + 1, greater<ii> ());

    int j = 1;
    for (int i = 1; i <= q; ++i) {
        while (j <= n * m && a[j].st > query[i].st) {
            ++scc;
            int u = a[j].nd.st;
            int v = a[j].nd.nd;
            int id = water(u, v);
            check[id] = true;
            for (int dir = 0; dir < 4; ++dir) {
                int x = u + dx[dir];
                int y = v + dy[dir];
                if (x >= 1 && x <= n && y >= 1 && y <= m) {
                    int id_new = water(x, y);
                    if (check[id_new]) 
                        join(id, id_new); 
                }
            }
            ++j;
        } 
        ans[query[i].nd] = scc;
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
}