#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 2e5 + 5;
int n, q, timeDFS = 0, curChain = 1;
int tin[maxN], tout[maxN], h[maxN], par[maxN][25], sz[maxN], node[maxN];
int chainID[maxN], chainHead[maxN];
int st[maxN << 2], lazy[maxN << 2];
vector<int> g[maxN];

void dfs(int u, int p) {
    sz[u] = 1;
    par[u][0] = p;
    for (auto v: g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int p) {
    if (!chainHead[curChain]) chainHead[curChain] = u;
    chainID[u] = curChain;
    tin[u] = ++timeDFS;
    node[timeDFS] = u;
    int nxt = -1;
    for (auto v: g[u]) {
        if (v == p) continue;
        if (nxt == -1 || (nxt != -1 && sz[nxt] < sz[v])) nxt = v;
    }
    if (nxt != -1) hld(nxt, u);
    for (auto v: g[u]) {
        if (v == p || v == nxt) continue;
        curChain++;
        hld(v, u);
    }
    tout[u] = timeDFS;
}

void push_down(int id) {
    if (lazy[id] == 0) return;
    lazy[id << 1] += lazy[id];
    lazy[id << 1|1] += lazy[id];
    st[id << 1] += lazy[id];
    st[id << 1|1] += lazy[id];
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int x) {
    if (l > v || r < u) return;

    if (u <= l && v >= r) {
        st[id] += x;
        lazy[id] += x;
        return;
    } 

    int mid = l + r >> 1;
    push_down(id);
    update(id << 1, l, mid, u, v, x);
    update(id << 1|1, mid + 1, r, u, v, x);

    st[id] = max(st[id << 1], st[id << 1|1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;

    if (u <= l && v >= r) return st[id];

    int mid = l + r >> 1;
    push_down(id);

    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int len = h[u] - h[v];
    for (int i = 18; i >= 0; --i)
        if (len >> i & 1) u = par[u][i];
    if (u == v) return u;
    for (int i = 18; i >= 0; --i) 
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

void upd(int u, int v, int x) {
    int acs = lca(u, v);
    while (chainID[u] != chainID[acs]) {
        update(1, 1, n, tin[chainHead[chainID[u]]], tin[u], x);
        u = par[chainHead[chainID[u]]][0];
    }
    while (chainID[v] != chainID[acs]) {
        update(1, 1, n, tin[chainHead[chainID[v]]], tin[v], x);
        v = par[chainHead[chainID[v]]][0];
    }
    if(h[u] < h[v]) 
        update(1, 1, n, tin[u], tin[v], x);
    else 
        update(1, 1, n, tin[v], tin[u], x);
}

int query(int u, int v) {
    int acs = lca(u, v), ans = 0;
    while (chainID[u] != chainID[acs]) {
        ans = max(ans, get(1, 1, n, tin[chainHead[chainID[u]]], tin[u]));
        u = par[chainHead[chainID[u]]][0];
    }
    while (chainID[v] != chainID[acs]) {
        ans = max(ans, get(1, 1, n, tin[chainHead[chainID[v]]], tin[v]));
        v = par[chainHead[chainID[v]]][0];
    }
    if (h[u] < h[v]) 
        ans = max(ans, get(1, 1, n, tin[u], tin[v]));
    else 
        ans = max(ans, get(1, 1, n, tin[v], tin[u]));

    return ans;
} 

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);

    for (int i = 1; i <= 18; ++i) 
        for (int u = 1; u <= n; ++u) 
            par[u][i] = par[par[u][i - 1]][i - 1];

    hld(1, 1);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, v, val; cin >> u >> v >> val;
            upd(u, v, val);
        } else if (type == 2) {
            int u, val; cin >> u >> val;
            update(1, 1, n, tin[u], tout[u], val);
        } else if (type == 3) {
            int u, v; cin >> u >> v;
            cout << query(u, v) << '\n';
        } else {
            int u; cin >> u;
            cout << get(1, 1, n, tin[u], tout[u]) << '\n';
        }
    }
}
 