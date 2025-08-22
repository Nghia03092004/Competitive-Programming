#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int maxN = 1e5 + 5;
const int inf = 1e18;
int n, m, st[maxN << 2];
 
void update(int id, int l, int r, int i, int val) {
    if (i < l || i > r)
        return ;
 
    if (l == r) {
        st[id] += val;
        return;
    }
 
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1|1, mid + 1, r, i, val);
 
    st[id] = max(st[id << 1], st[id << 1|1]);
}
 
int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return -inf;
 
    if (l >= u && r <= v) return st[id];
 
    int mid = (l + r) >> 1;
 
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}
 
main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
 
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t) cout << get(1, 1, n, l, r) << '\n';
        else update(1, 1, n, l, r);
    }
}