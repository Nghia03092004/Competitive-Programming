#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 2e5 + 5;
int n, q, ti;
int in[maxN], out[maxN], a[maxN], b[maxN];
int st[maxN << 2], flip[maxN << 2];
vector<int> g[maxN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = b[l];
        return;
    }

    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);

    st[id] = (st[id << 1] + st[id << 1|1]);
}

void lazy(int id, int l, int r, int mid) {
    if (flip[id] == 1) {
        flip[id] ^= 1;
        flip[id << 1] ^= 1;
        flip[id << 1|1] ^= 1;

        st[id << 1] = (mid - l + 1) - st[id << 1];
        st[id << 1|1] = (r - mid) - st[id << 1|1];
    }
}

void update(int id, int l, int r, int u, int v) {
    if (l > v || r < u) 
        return;

    if (l >= u && r <= v) {
        st[id] = (r - l + 1) - st[id];
        flip[id] ^= 1;
        return;
    }

    int mid = l + r >> 1;
    lazy(id, l, r, mid);
    update(id << 1, l, mid, u, v);
    update(id << 1|1, mid + 1, r, u, v);

    st[id] = (st[id << 1] + st[id << 1|1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return 0;

    if (l >= u && r <= v)
        return st[id];

    int mid = l + r >> 1;
    lazy(id, l, r, mid);
    return get(id << 1, l, mid, u, v) + get(id << 1|1, mid + 1, r, u, v);
}

void DFS(int u, int par) {
    in[u] = out[u] = ++ti;
    for (auto v: g[u]) 
        if (v != par) {
            DFS(v, u);
            out[u] = max(out[u], out[v]);
        }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g[p].push_back(i);
    }

    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    DFS(1, -1);

    for (int i = 1; i <= n; ++i) 
        b[in[i]] = a[i];

    build(1, 1, n);

    cin >> q;
    while (q--) {
        string s; cin >> s;
        if (s[0] == 'g') {
            int u; cin >> u;
            cout << get(1, 1, n, in[u], out[u]) << '\n';
        } else {
            int u; cin >> u;
            update(1, 1, n, in[u], out[u]);
        }
    }
}