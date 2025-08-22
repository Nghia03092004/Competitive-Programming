#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define iii pair<int, ii> 
#define fi first
#define se second

#define oo 1e9

const int maxN = (int) 1e5 + 5;
int n, m, q, cnt;
int a[maxN], p[maxN], h[maxN], f[maxN], head[maxN], heavy[maxN], pos[maxN];
iii st[maxN << 2];
vector<ii> g[maxN];
char s[10];

int DFS(int i, int j) {
    int sz = 1, smsz = 0;
    for (int s = 0; s < g[i].size(); ++s) {
        int u = g[i][s].fi;
        int v = g[i][s].se;
        if (u != j) {
            p[u] = i;
            h[u] = h[i] + 1;
            f[v] = u;
            int ssz = DFS(u, i);
            sz += ssz;
            if (smsz < ssz) 
                smsz = ssz, heavy[i] = u;
        }
    }
    return sz;
}
 
void HLD(int i, int j) {
    head[i] = j, pos[i] = cnt++;
    if (heavy[i]) 
        HLD(heavy[i], j);
    for (int s = 0; s < g[i].size(); ++s) {
        int u = g[i][s].fi;
        if (u != heavy[i] && u != p[i])
            HLD(u, u);
    }
}
 
void fix(int &a, int &b) {
    int c = -a;
    a = -b;
    b = c;
}
 
void down(int id) {
    if (st[id].fi != 0) {
        st[id << 1].fi ^= 1;
        fix(st[id << 1].se.fi, st[id << 1].se.se);
        st[id << 1|1].fi ^= 1;
        fix(st[id << 1|1].se.fi, st[id << 1|1].se.se);
        st[id].fi = 0;
    }
}

void up1(int id, int l, int r, int i, int val) {
    if (l > i || r < i)
        return;

    if (l == r) {
        st[id].se.fi = st[id].se.se = val;
        return;
    }

    down(id);
    int mid = l + r >> 1;
    up1(id << 1, l, mid, i, val);
    up1(id << 1|1, mid + 1, r, i, val);
    st[id].se.fi = min(st[id << 1].se.fi, st[id << 1|1].se.fi);
    st[id].se.se = max(st[id << 1].se.se, st[id << 1|1].se.se);    
}

void up2(int id, int l, int r, int u, int v) {
    if (l > v || r < u) 
        return;

    if (l >= u && r <= v) {
        st[id].fi ^= 1;
        fix(st[id].se.fi, st[id].se.se);
        return;
    }

    down(id);
    int mid = l + r >> 1;
    up2(id << 1, l, mid, u, v);
    up2(id << 1|1, mid + 1, r, u, v);
    st[id].se.fi = min(st[id << 1].se.fi, st[id << 1|1].se.fi);
    st[id].se.se = max(st[id << 1].se.se, st[id << 1|1].se.se);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return -oo;

    if (l >= u && r <= v) 
        return st[id].se.se;

    down(id);
    int mid = l + r >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}

void Negate(int x, int y) {
    for (; head[x] != head[y]; y = p[head[y]]) {
        if (h[head[x]] > h[head[y]]) 
            swap(x, y);
        up2(1, 1, n - 1, pos[head[y]], pos[y]);
    }
    up2(1, 1, n - 1, min(pos[x], pos[y]) + 1, max(pos[x], pos[y]));
}

int query(int x, int y) {
    int res = -oo;
    for (; head[x] != head[y]; y = p[head[y]]) {
        if (h[head[x]] > h[head[y]]) 
            swap(x, y);
        res = max(res, get(1, 1, n - 1, pos[head[y]], pos[y]));
    }
    res = max(res, get(1, 1, n - 1, min(pos[x], pos[y]) + 1, max(pos[x], pos[y])));
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            heavy[i] = 0;
            g[i].clear();
        }

        for (int i = 1; i <= n - 1; ++i) {
            int x, y, z; cin >> x >> y >> z;
            g[x].push_back({y, i});
            g[y].push_back({x, i});
            a[i] = z;
        }

        DFS(1, -1);
        HLD(1, 1);

        for (int i = 1; i <= n - 1; ++i) 
            up1(1, 1, n - 1, pos[f[i]], a[i]);

        while (true) {
            cin >> s;
            if (s[0] == 'C') {
                int po, val; cin >> po >> val;
                up1(1, 1, n - 1, pos[f[po]], val); 
            } else if (s[0] == 'N') {
                int u, v; cin >> u >> v;
                Negate(u, v);
            } else if (s[0] == 'Q') {
                int u, v; cin >> u >> v;
                if (u == v) 
                    cout << 0 << '\n';
                else 
                    cout << query(u, v) << '\n';
            } else 
                break;
        }
    }
}
 