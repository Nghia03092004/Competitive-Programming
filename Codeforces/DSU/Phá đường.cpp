#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define st first
#define nd second


const int maxN = (int) 1e5 + 5;
int n, m, q;
int par[maxN], sz[maxN];
ii g[maxN];
vector<int> ans;
bool check[maxN];
int query[maxN];
int scc;

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        --scc;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
    scc = n;
    for (int i = 1; i <= m; ++i) 
        cin >> g[i].st >> g[i].nd;

    for (int i = 1; i <= q; ++i) {
        cin >> query[i];
        check[query[i]] = true;
    }

    for (int i = 1; i <= m; ++i) 
        if (!check[i]) 
            join(g[i].st, g[i].nd);

    ans.push_back(scc);
    for (int i = q; i >= 2; --i) {
        join(g[query[i]].st, g[query[i]].nd);
        ans.push_back(scc);
    }
    reverse(ans.begin(), ans.end());

    for (auto x: ans) cout << x << '\n'; 
}