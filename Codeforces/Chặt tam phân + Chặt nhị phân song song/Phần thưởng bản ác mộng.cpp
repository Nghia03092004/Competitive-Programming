#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int maxN = (int) 3e5 + 5;
int n, Q;
pair<int, int> a[maxN];
int l[maxN], r[maxN], ans[maxN], f1[maxN], f2[maxN];
vector<int> queries[maxN];

struct Query {
    int l, r, t;
} q[maxN];

void update_1(int pos, int val) {
    for (int i = pos; i <= n; i += i & -i)
        f1[i] += val;
}

void update_2(int pos, int val) {
    for (int i = pos; i <= n; i += i & -i)
        f2[i] += val;
}

int get_1(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i & -i) 
        ret += f1[i];
    return ret;
}

int get_2(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i & -i) 
        ret += f2[i];
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> Q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= Q; ++i) {
        cin >> q[i].l >> q[i].r >> q[i].t;
        l[i] = 0, r[i] = n, ans[i] = 0;
    }

    while (true) {
        bool check = true;
        for (int i = 1; i <= Q; ++i) {
            if (l[i] > r[i]) continue;
            check = false;
            queries[(l[i] + r[i]) / 2].push_back(i);
        }
        if (check) break;
        for (int ti = 0; ti <= n; ++ti) {
            if (ti) {
                update_1(a[ti].second, a[ti].first);
                update_2(a[ti].second, 1);
            }
            for (auto id: queries[ti]) {
                if (get_1(q[id].r) - get_1(q[id].l - 1) <= q[id].t) 
                    l[id] = ti + 1, ans[id] = get_2(q[id].r) - get_2(q[id].l - 1); 
                else 
                    r[id] = ti - 1;
            }
            queries[ti].clear();
        }
        for (int i = 1; i <= n; ++i)
            f1[i] = f2[i] = 0;
    }
    for (int i = 1; i <= Q; ++i) 
        cout << ans[i] << '\n';
}