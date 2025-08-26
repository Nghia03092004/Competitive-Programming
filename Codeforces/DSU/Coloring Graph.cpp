#include<bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define st first
#define nd second

const int maxN = (int) 1e5 + 5;
int n, m, ans;
int c[maxN], par[maxN];
vector<int> g[maxN];
map<ii, int> mp;

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (g[x].size() < g[y].size()) swap(x, y);
    if (x != y) {
        par[y] = x;
        for (auto i: g[y]) {
            ans += mp[{x, c[i]}];
            g[x].push_back(i);
        }
        for (auto i: g[y]) 
            mp[{x, c[i]}]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        g[i].push_back(i);
        cin >> c[i];
        mp[{i, c[i]}] = 1;
    }    

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        join(u, v);
        cout << ans << '\n';
    }
}