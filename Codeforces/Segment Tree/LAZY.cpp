#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
const int maxN = 1e5 + 5;
int n, m;
int st[maxN << 2], lazy[maxN << 2];
 
void down(int id) {
    lazy[id << 1] += lazy[id];
    lazy[id << 1|1] += lazy[id];
    st[id << 1] += lazy[id];
    st[id << 1|1] += lazy[id];
 
    lazy[id] = 0; // reset
}
 
void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || u > r) return;
 
    if (u <= l && r <= v) {
        st[id] += val;
        lazy[id] += val;
        return;
    }
 
    int mid = (l + r) >> 1;
    down(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1|1, mid + 1, r, u, v, val);
 
    st[id] = max(st[id << 1], st[id << 1|1]);
}
 
int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return -inf;
 
    if (l >= u && r <= v) return st[id];
 
    int mid = (l + r) >> 1;
    down(id);
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}
 
main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (m--) {
        int t, l, r, k;
        cin >> t >> l >> r;
        if (!t) {
            cin >> k;
            update(1, 1, n, l, r, k);
        } else cout << get(1, 1, n, l, r) << '\n';
    }
}