#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define iiii pair<ii, ii>
#define st first
#define nd second

const int maxN = (int) 2e5 + 5;
int n, m, q;
int par[maxN], h[maxN];
vector<iii> road;
vector<iiii> query;
bool ans[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) 
        par[x] = y;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        par[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v;
        w = max(h[u], h[v]);
        road.push_back({w, {u, v}});
    }
    sort(road.begin(), road.end());
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int a, b, c; cin >> a >> b >> c;
        query.push_back({{c + h[a], i}, {a, b}});
    }
    sort(query.begin(), query.end());
    int j = 0;
    for (auto x: query) {
        int fuel = x.st.st;
        int start = x.nd.st;
        int goal = x.nd.nd;
        while (j < road.size() && road[j].st <= fuel) {
            int u = road[j].nd.st;
            int v = road[j].nd.nd;
            join(u, v);
            ++j;
        }
        if (acs(start) == acs(goal))
            ans[x.st.nd] = true;
    }
    for (int i = 1; i <= q; ++i) 
        cout << (ans[i] == true ? "YES" : "NO") << '\n';


    return 0;
}