#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int>
#define st first
#define nd second

const int maxN = (int) 2e5 + 5;
int n, m, q;
int a[maxN], par[maxN], sz[maxN], sum[maxN];
ii edge[maxN];
vector<int> ans, d[maxN];
bool check[maxN];
multiset<int, greater<int>> ms;

struct query {
    char type;
    int id, val;
} query[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);

    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x; sz[x] += sz[y];
        if (ms.find(sum[x]) != ms.end()) ms.erase(ms.find(sum[x]));
        if (ms.find(sum[y]) != ms.end()) ms.erase(ms.find(sum[y]));
        sum[x] += sum[y];
        ms.insert(sum[x]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i].push_back(a[i]);
        sum[i] = a[i];
    }
    for (int i = 1; i <= m; ++i) 
        cin >> edge[i].st >> edge[i].nd;
    for (int i = 1; i <= q; ++i) {
        cin >> query[i].type;
        if (query[i].type == 'D') {
            cin >> query[i].id;
            check[query[i].id] = true;
        } else {
            cin >> query[i].id >> query[i].val;
            d[query[i].id].push_back(query[i].val);
            sum[query[i].id] = query[i].val;
        }
    }
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; ++i) 
        if (acs(i) == i) 
            ms.insert(sum[i]);
    for (int i = 1; i <= m; ++i) 
        if (!check[i])
            join(edge[i].st, edge[i].nd);
    for (int i = q; i >= 1; --i) {
        if (query[i].type == 'D') {
            ans.push_back(*ms.begin());
            int index = query[i].id;
            join(edge[index].st, edge[index].nd);
        } else {
            ans.push_back(*ms.begin());
            int index = query[i].id;
            d[index].pop_back();
            int value = d[index].back();
            int prevalue = query[i].val;
            if (ms.find(sum[acs(index)]) != ms.end()) 
                ms.erase(ms.find(sum[acs(index)]));
            sum[acs(index)] -= prevalue;
            sum[acs(index)] += value;
            ms.insert(sum[acs(index)]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int x: ans) cout << x << '\n';
}