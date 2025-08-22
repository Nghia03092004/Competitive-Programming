#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
int n;
int sz[maxN], dp[maxN], f[maxN], ans[maxN];
vector<int> g[maxN];
bool is_centroid[maxN];
vector<pair<int, int>> d_global, d_internal;

void DFS(int u, int par) {
    sz[u] = 1;
    for (auto v: g[u]) 
        if (v != par && !is_centroid[v]) {
            DFS(v, u);
            sz[u] += sz[v];
        }
}

void up(int pos, int val) {
    ++pos;
    for (int i = pos; i <= n + 1; i += i & -i)
        f[i] += val;
}

int get(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i & -i) 
        ret += f[i];
    return ret;
}

int query(int l, int r) {
    ++l, ++r;
    int ret = 0;
    if (r >= 1) 
        ret += get(r);
    if (l - 1 >= 1)
        ret -= get(l - 1);
    return ret;
}

int find_centroid(int u, int tree_sz, int par) {
    for (auto v: g[u]) 
        if (v != par && !is_centroid[v] && sz[v] > tree_sz / 2) 
            return find_centroid(v, tree_sz, u);
    return u;
}

void DFS(int u, int par, int h) {
    d_global.push_back({h, u});
    d_internal.push_back({h, u});

    for (auto v: g[u]) 
        if (v != par && !is_centroid[v])
            DFS(v, u, h + 1);
}

void solve(vector<pair<int, int>> p, int neg) {
    int sz = 0;
    int sum = 0;
    for (auto v: p) {
        ++sz;
        sum += v.first;
    }

    for (auto e: p) {
        int v = e.second;
        int d = e.first;
        ans[v] += ((sz - 1) * d + sum - d) * neg;
    }
}

void build_centroid(int u, int pre_centroid) {
    DFS(u, -1);
    int centroid = find_centroid(u, sz[u], -1);


    d_global.push_back({0, centroid});
    for (auto v: g[centroid])
        if (!is_centroid[v]) {
            DFS(v, centroid, 1);
            solve(d_internal, -1);
            d_internal.clear();
        }
    solve(d_global, 1);
    d_global.clear();


    is_centroid[centroid] = true;

    for (auto v: g[centroid]) 
        if (!is_centroid[v])
            build_centroid(v, centroid);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build_centroid(1, -1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
}