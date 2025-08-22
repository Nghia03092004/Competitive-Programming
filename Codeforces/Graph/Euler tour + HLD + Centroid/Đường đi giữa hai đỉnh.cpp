#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 4e5 + 5;
const int L = log2(maxN) + 2;
int n, q, cnt;
int a[maxN], in[maxN], out[maxN], f[maxN], w_edge[maxN], ver[maxN], h[maxN];
vector<pair<int, pair<int, int>>> g[maxN];
int P[maxN][L];

void up(int pos, int x) {
    for (int i = pos; i <= 2 * n; i += i & -i) 
        f[i] += x;
}

int get(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i & -i) 
        ret += f[i];
    return ret;
}

void DFS(int u, int par) {
    in[u] = ++cnt;
    for (auto e: g[u]) {
        int v = e.first;
        int w = e.second.first;
        int id = e.second.second;
        if (v != par) {
            P[v][0] = u;
            h[v] = h[u] + 1;
            DFS(v, u);

            ver[id] = v;
            w_edge[id] = w;

            up(in[v], w);
            up(out[v], -w);
        }
    }
    out[u] = ++cnt;
}

void init() {
    for (int i = 1; (1 << i) <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            P[j][i] = P[P[j][i - 1]][i - 1];
}

int LCA(int u, int v) {
    if  (h[u] < h[v]) 
        swap(u, v);
    int z = log2(h[u]);
    for (int i = z; i >= 0; --i) 
        if (h[u] - (1 << i) >= h[v])
            u = P[u][i];
    if (u == v) 
        return u;
    for (int i = z; i >= 0; --i) 
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    return P[u][0];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, {w, i}});
        g[v].push_back({u, {w, i}});
    }

    DFS(1, -1);
    init();

    for (int i = 1; i <= n; ++i) {
        up(in[i], a[i]);
        up(out[i], -a[i]);
    }

    cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x, y; cin >> x >> y;

            int s = ver[x];

            up(in[s], -w_edge[x]);
            up(out[s], w_edge[x]);
            w_edge[x] = y;
            up(in[s], w_edge[x]);
            up(out[s], -w_edge[x]);
        } else {
            int u, v; cin >> u >> v;
            cout << get(in[u]) + get(in[v]) - 2 * get(in[LCA(u, v)]) << '\n';
        }
    }
}