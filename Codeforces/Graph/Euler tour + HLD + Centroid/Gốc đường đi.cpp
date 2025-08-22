#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 4e5 + 5;
int n, q, cnt;
int a[maxN], in[maxN], out[maxN], f[maxN];
vector<int> g[maxN];

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
    for (auto v: g[u]) {
        if (v != par) 
            DFS(v, u);
    }
    out[u] = ++cnt;
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

    for (int i = 1; i <= n; ++i) {
        up(in[i], a[i]);
        up(out[i], -a[i]);
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            up(in[s], -a[s]);
            up(out[s], a[s]);
            a[s] = x;
            up(in[s], a[s]);
            up(out[s], -a[s]);
        } else {
            int v; cin >> v;
            cout << get(in[v]) << '\n';
        }
    }
}