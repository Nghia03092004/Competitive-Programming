#include<bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 3e5 + 5;
int n, m, a[N], lazy[N * 4], st[N * 4];
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    st[id] = min(st[id << 1], st[id << 1|1]);
}
 
void fix(int id) {
    lazy[id << 1] += lazy[id];
    st[id << 1] += lazy[id];
    lazy[id << 1|1] += lazy[id];
    st[id << 1|1] += lazy[id];
    
    lazy[id] = 0; 
}
 
void update (int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    
    if (l >= u && r <= v) {
        st[id] += val;
        lazy[id] += val;
        return;
    }
    
    int mid = (l + r) >> 1;
    fix(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1|1, mid + 1, r, u, v, val);
    
    st[id] = min(st[id << 1], st[id << 1|1]);
}
 
int getLeft(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u || st[id] > k) return -1;
    if (l == r) return l;
    
    int mid = (l + r) >> 1;
    fix(id);
    int left = getLeft(id << 1, l, mid, u, v, k);
    if (left != -1) return left;
    return getLeft(id << 1|1, mid + 1, r, u, v, k);
}
 
int getRight(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u || st[id] > k) return -1;
    if (l == r) return l;
    
    int mid = (l + r) >> 1;
    fix(id);
    int right = getRight(id << 1|1, mid + 1, r, u, v, k);
    if (right != -1) return right;
    return getRight(id << 1, l, mid, u, v, k);
}
 
main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    while (m--) {
        int type, l, r, k;
        cin >> type >> l >> r >> k;
        if (type == 1) update(1, 1, n, l, r, k);
        else cout << getLeft(1, 1, n, l, r, k) << ' ' << getRight(1, 1, n, l, r, k) << '\n';
    }
}