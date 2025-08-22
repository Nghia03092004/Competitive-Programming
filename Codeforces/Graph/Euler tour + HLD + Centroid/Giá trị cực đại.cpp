#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 2e5 + 5;
int n, q, cnt;
int a[maxN], pos[maxN], head[maxN], heavy[maxN], h[maxN], p[maxN];
vector<int> g[maxN];
int st[maxN << 2];

int DFS(int u, int par) {
    int mx_son_sz = 0;
    int cur_sz = 1;
    for (auto v: g[u]) {
        if (v != par) {
            h[v] = h[u] + 1;
            p[v] = u;
            int son_sz = DFS(v, u);

            if (mx_son_sz < son_sz) 
                mx_son_sz = son_sz, heavy[u] = v;

            cur_sz += son_sz;
        }
    }
    return cur_sz;
}

void HLD(int u, int h) {
    head[u] = h;
    pos[u] = ++cnt;

    if (heavy[u] != 0) 
        HLD(heavy[u], h);

    for (auto v: g[u]) 
        if (v != p[u] && v != heavy[u]) 
            HLD(v, v);  
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) 
        return;

    if (l == r) {
        st[id] = val;
        return;
    }

    int mid = l + r >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1|1, mid + 1, r, pos, val);

    st[id] = max(st[id << 1], st[id << 1|1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) 
        return -2e9;

    if (l >= u && r <= v) 
        return st[id];

    int mid = l + r >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}

int query(int x, int y) {
    int ans = 0;
    for (;head[x] != head[y]; y = p[head[y]]) {
        if (h[head[x]] > h[head[y]]) 
            swap(x, y);
        ans = max(ans, get(1, 1, n, pos[head[y]], pos[y]));
    }

    if (h[x] > h[y])
        swap(x, y);

    ans = max(ans, get(1, 1, n, pos[x], pos[y]));

    return ans;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    DFS(1, -1);
    HLD(1, 1);

    for (int i = 1; i <= n; ++i)
        update(1, 1, n, pos[i], a[i]);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x, y; cin >> x >> y;
            update(1, 1, n, pos[x], y);
        } else {
            int x, y; cin >> x >> y;
            cout << query(x, y) << ' ';
        }
    } 
}