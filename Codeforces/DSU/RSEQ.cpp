#include<bits/stdc++.h>

using namespace std;

#define int long long
const int inf = (int) 1e9;
const int maxN = (int) 5e5 + 5;
int n, q, ma = -inf;
int a[maxN], query[maxN], sum[maxN], par[maxN], sz[maxN];
bool check[maxN];
vector<int> ans;

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
        sum[x] += sum[y];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> query[i];
        check[query[i]] = true;
    }
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        if (!check[i]) {
            if (i - 1 >= 1 && !check[i - 1]) {
                join(i, i - 1);
            }
            ma = max(ma, sum[acs(i)]);
        }
    }

    for (int i = q; i >= 1; --i) {
        ans.push_back(ma);
        check[query[i]] = false;
        if (query[i] + 1 <= n && !check[query[i] + 1]) {
            join(query[i], query[i] + 1);
            ma = max(ma, sum[acs(query[i])]);
        }
        if (query[i] - 1 >= 1 && !check[query[i] - 1]) {
            join(query[i], query[i] - 1);
            ma = max(ma, sum[acs(query[i])]);
        }
        ma = max(ma, sum[acs(query[i])]);
    }

    reverse(ans.begin(), ans.end());
    for (int x: ans) cout << x << '\n';
}