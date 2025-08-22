#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
const int N = 1e5 + 5;
int n, m, q;
int a[N], st[N << 2], lazy[N << 2];
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    st[id] = (st[id << 1] + st[id << 1|1]) % m;
}
 
void fix(int id, int l, int r) {
    (lazy[id << 1] += lazy[id]) %= m;
    (lazy[id << 1|1] += lazy[id]) %= m;
    
    int mid = (l + r) >> 1;
    (st[id << 1] += (mid - l + 1) * lazy[id]) %= m;
    (st[id << 1|1] += (r - mid) * lazy[id]) %= m;
    
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        (lazy[id] += val) %= m;
        (st[id] += (r - l + 1) * val) %= m;
        return; 
    }
    
    int mid = (l + r) >> 1;
    fix(id, l, r);
    update(id << 1, l, mid, u, v, val);
    update(id << 1|1, mid + 1, r, u, v, val);
    
    st[id] = (st[id << 1] + st[id << 1|1]) % m;
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    fix(id, l, r);
    return (get(id << 1, l, mid, u, v) + get(id << 1|1, mid + 1, r, u, v)) % m; 
}
 
main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    while (q--) {
        int type, l, r, x;
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> x;
            update(1, 1, n, l, r, x);
        }
        else cout << get(1, 1, n, l, r) % m << '\n';
    }
}