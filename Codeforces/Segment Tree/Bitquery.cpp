#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
const int sup = -1e18;
const int N = 1e5 + 5;
int n, m, a[N], st[4*N], lazy[N*4];
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    st[id] = st[id << 1] | st[id << 1|1];
} 
 
void fix(int id) {
    if (lazy[id] != 0) {
        lazy[id << 1] = lazy[id];
        st[id << 1] = lazy[id];
        lazy[id << 1|1] = lazy[id];
        st[id << 1|1] = lazy[id];
        
        lazy[id] = 0;
    }
} 
 
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    
    if (l >= u && r <= v) {
        st[id] = val;
        lazy[id] = val;
        return;
    }
    
    int mid = l + r >> 1;
    fix(id);
    update(id*2, l, mid, u, v, val);
    update(id*2 + 1, mid + 1, r, u, v, val);
    
    st[id] = st[id << 1] | st[id << 1|1];
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    
    if (l >= u && r <= v) return st[id];
 
    int mid = (l + r) >> 1;
    fix(id);
    return get(id << 1, l, mid, u, v) | get(id << 1|1, mid + 1, r, u, v);
}
 
main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    while (m--) {
        int type, x, y, k;
        cin >> type >> x >> y;
        if (type == 1) {
            cin >> k;
            update(1, 1, n, x, y, k);   
        } else cout << get(1, 1, n, x, y) << '\n';
    }
}