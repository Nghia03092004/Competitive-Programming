#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 5;
int n, m, a[N], st[N << 2];
 
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
 
void update (int id, int l, int r, int i, int val) {
    if (i < l || i > r) return;
    
    if (l == r) {
        st[id] = val;
        return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1|1, mid + 1, r, i, val);
    
    st[id] = min(st[id << 1], st[id << 1|1]);
}
 
int getLeft(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u || st[id] > k) return -1;
    if (l == r) return l;
    
    int mid = (l + r) >> 1;
    int left1 = getLeft(id << 1, l, mid, u, v, k);
    if (left1 != -1) return left1;
    return getLeft(id << 1|1, mid + 1, r, u, v, k);
}
 
int getRight(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u || st[id] > k) return -1;
    if (l == r) return l;
    
    int mid = (l + r) >> 1;
    int right = getRight(id << 1|1, mid + 1, r, u, v, k);
    if (right != -1) return right;
    return getRight(id << 1, l, mid, u, v, k);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    while (m--) {
        int type, l, r, k;
        cin >> type >> l >> r;
        if (type == 1) update(1, 1, n, l, r);
        else {
            cin >> k;
            cout << getLeft(1, 1, n, l, r, k) << ' ' << getRight(1, 1, n, l, r, k) << '\n';
        }
    }
}