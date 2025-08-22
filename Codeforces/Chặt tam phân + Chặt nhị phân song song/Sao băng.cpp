#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 3e5 + 5;
int n, m, Q;
pair<int, pair<int, int>> q[maxN];
int f[maxN], ans[maxN], a[maxN], need[maxN], l[maxN], r[maxN];
vector<int> queries[maxN], g[maxN];

void update(int pos, int val) {
    for (int i = pos; i <= m; i += i & -i)
        f[i] += val;
}

int get(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i & -i) {
        ret += f[i];
        ret = min(ret, (int) 1e12);
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) 
        cin >> need[i];

    cin >> Q;
    for (int i = 1; i <= Q; ++i) 
        cin >> q[i].second.first >> q[i].second.second >> q[i].first;

    for (int i = 1; i <= n; ++i) 
        l[i] = 0, r[i] = Q, ans[i] = -1;

    while (true) {
        bool check = true;
        for (int i = 1; i <= n; ++i) {
            if (l[i] > r[i]) continue;
            check = false;
            queries[(l[i] + r[i]) / 2].push_back(i);
        }
        if (check) break;

        for (int time = 0; time <= Q; ++time) {
            if (time) {
                int l = q[time].second.first;
                int r = q[time].second.second;
                int val = q[time].first;
                if (l <= r) {
                    update(l, val);
                    update(r + 1, -val);
                } else {
                    swap(l, r);
                    update(1, val);
                    update(l + 1, -val);
                    update(r, val);
                }
            }
            for (auto id: queries[time]) {
                int sum = 0;
                for (auto pos: g[id]) 
                    sum += get(pos);
                if (sum >= need[id]) 
                    r[id] = time - 1, ans[id] = time;
                else 
                    l[id] = time + 1;
            }
            queries[time].clear();
        }
        memset(f, 0, sizeof f);
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1)
            cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
}