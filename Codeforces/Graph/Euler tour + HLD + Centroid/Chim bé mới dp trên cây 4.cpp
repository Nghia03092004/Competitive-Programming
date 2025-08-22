#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
int n, q, l, w, mx_h, ans;
int sz[maxN], f[maxN];
bool ok;
bool del[maxN];
int edge[maxN];
vector<pair<int, int>> g[maxN];
vector<pair<int, int>> d_global, d_internal;

void up(int pos, int val) {
    ++pos;
    for (int i = pos; i <= mx_h + 1; i += i & -i) 
        f[i] += val;
}

int get(int pos) {
    int ret = 0;
    ++pos;
    for (int i = pos; i; i -= i & -i)
        ret += f[i];
    return ret;
}

void DFS(int u, int par) {
    sz[u ] = 1;
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

void mx_depth(int u, int par, int h) {
    mx_h = max(mx_h, h);
    for (auto e: g[u]) {
        int v = e.first;
        if (v != par && !del[v])
            mx_depth(v, u, h + 1);
    }
}

void solve(vector<pair<int, int>> p, int sign) {
    int j = p.size() - 1;
    sort(p.begin(), p.end());

    for (auto v: p) 
        up(v.second, 1);

    for (auto v: p) {
        while (j >= 0 && v.first + p[j].first > w) {
            up(p[j].second, -1);
            --j;
        }
        if (j >= 0 && v.second <= l) 
            ans += get(min(mx_h, l - v.second)) * sign;
    }

    while (j >= 0) {
        up(p[j].second, -1);
        --j;
    }
}

void DFS_2(int u, int par, int h, int c) {
    d_global.push_back({c, h});
    d_internal.push_back({c, h});

    for (auto e: g[u]) {
        int v = e.first;
        if (!del[v] && v != par) 
            DFS_2(v, u, h + 1, c + e.second);
    }
}

void build_centroid(int u) {
    DFS(u, -1);

    int centroid = get_centroid(u, sz[u], -1);

    mx_h = 0;
    for (auto e: g[centroid]) {
        int v = e.first;
        if (!del[v])
            mx_depth(v, centroid, 1);
    }

    d_global.push_back({0, 0});
    for (auto e: g[centroid]) {
         int v = e.first;
         if (!del[v]) {
            DFS_2(v, centroid, 1, e.second);
            solve(d_internal, -1);
            d_internal.clear();
         }
    }

    solve(d_global, 1);
    d_global.clear();

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

    cin >> n >> l >> w;

    for (int i = 2; i <= n; ++i) {
        int u, w; cin >> u >> w;
        g[u].push_back({i, w});
        g[i].push_back({u, w});
    }

    build_centroid(1);

    cout << (ans - n) / 2;
}