#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 1e5 + 5;
int n, root;
int sz[maxN], f[maxN];
vector<int> g[maxN], new_g[maxN];
bool is_centroid[maxN];

void DFS(int u, int par) {
    sz[u] = 1;
    for (auto v: g[u]) 
        if (v != par && !is_centroid[v]) {
            DFS(v, u);
            sz[u] += sz[v];
        }
}

int find_centroid(int u, int tree_sz, int par) {
    for (auto v: g[u]) 
        if (v != par && !is_centroid[v] && sz[v] > tree_sz / 2) 
            return find_centroid(v, tree_sz, u);
    return u;
}

void build_centroid(int u, int pre_centroid) {
    DFS(u, -1);
    int centroid = find_centroid(u, sz[u], -1);

    if (root == 0)
        root = centroid;

    is_centroid[centroid] = true;
    if (pre_centroid != -1) 
        new_g[pre_centroid].push_back(centroid);

    for (auto v: g[centroid]) 
        if (!is_centroid[v])
            build_centroid(v, centroid); 
}

void DFS_2(int u) {
    for (auto v: new_g[u]) {
        DFS_2(v);
        f[u] = max(f[u], f[v] + 1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build_centroid(1, -1);
    DFS_2(root);

    for (int i = 1; i <= n; ++i)
        cout << (char) ('Z' - f[i]) << ' ';
}