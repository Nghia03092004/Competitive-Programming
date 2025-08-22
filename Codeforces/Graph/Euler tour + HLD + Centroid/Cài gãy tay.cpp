#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e5 + 5;
int n, q, L, R, mx_h, ans_1, ans_2, res = -1, diameter, imx_h;
int sz[maxN], best[maxN], ID[maxN];
bool ok;
bool del[maxN];
int edge[maxN];
vector<pair<int, int>> g[maxN];
pair<int, int> st[maxN << 2];

void build(int id, int l, int r) {
    if (l == r) {
        ID[l] = id;
        return;
    }

    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
}

void update(int pos, pair<int, int> val) {
    int p = ID[pos];
    st[p] = max(st[p], val);
    while (p > 0) {
        p /= 2;
        st[p] = max(st[p << 1], st[p << 1|1]);
    }
}

pair<int, int> get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) 
        return {-1e9, -1e9};

    if (l >= u && r <= v) 
        return st[id];

    int mid = l + r >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}

void DFS(int u, int par) {
    sz[u] = 1;
    for (auto e: g[u]) {
        int v = e.first;
        if (v != par && !del[v]) {
            DFS(v, u);
            sz[u] += sz[v];
        }
    }
}

int get_centroid(int u, int tree_sz, int par) {
    for (auto e: g[u]) {
        int v = e.first;
        if (v != par && !del[v] && sz[v] > tree_sz / 2) 
            return get_centroid(v, tree_sz, u);
    }
    return u;
}

void DFS_2(int u, int par, int h, int sum, int c, int type) {
    if (type == 0) {
        pair<int, int> v = get(1, 0, mx_h, L - h, R - h);
        pair<int, int> p = {-1e9, -1e9};
        if (v != p && v.first + sum >= 0) {
            ok = true;
            if (res < c) {
                res = c;
                ans_1 = u;
                ans_2 = v.second;
            }
        }
    } else 
        update(h, {sum, u});

    for (auto e: g[u]) {
        int v = e.first;
        if (v != par && !del[v])
            DFS_2(v, u, h + 1, sum + ((e.second >= c) ? 1 : -1), c, type);
    }
}

bool check(int mid, int centroid) {
    update(0, {0, centroid});
    ok = false;
    for (auto e: g[centroid]) {
        int v = e.first;
        if (!del[v]) {
            DFS_2(v, centroid, 1, (e.second >= edge[mid]) ? 1 : -1, edge[mid], 0);
            DFS_2(v, centroid, 1, (e.second >= edge[mid]) ? 1 : -1, edge[mid], 1);
        }
    }
    for (int i = 0; i <= 4 * mx_h; ++i)
            st[i] = {-1e9, -1e9};
    return ok;
}

void mx_depth(int u, int par, int h) {
    mx_h = max(mx_h, h);
    for (auto e: g[u]) {
        int v = e.first;
        if (v != par && !del[v])
            mx_depth(v, u, h + 1);
    }
}

void build_centroid(int u) {
    DFS(u, -1);

    int centroid = get_centroid(u, sz[u], -1);

    mx_h = 0;
    vector<int> dist;
    for (auto e: g[centroid]) {
        int v = e.first;
        if (!del[v]) {
            imx_h = 0;
            mx_depth(v, centroid, 1);
        }
    }

    build(1, 0, mx_h);

    int l = 1, r = n - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (res > edge[mid] || check(mid, centroid)) 
            l = mid + 1;
        else 
            r = mid - 1;
    }

    del[centroid] = true;

    for (auto e: g[centroid]) {
        int v = e.first;
        if (!del[v])
            build_centroid(v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> L >> R;
    for (int i = 0; i <= 4 * n; ++i) 
        st[i] = {-1e9, -1e9};

    for (int i = 1; i <= n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edge[i] = w;
    }

    sort(edge + 1, edge + n);
    build_centroid(1);

    cout << ans_1 << ' ' << ans_2 << '\n';
}