#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
int n, q;
int cnt[10];
int a[N], st[N << 2][10], lazy[N << 2];
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id][a[l]] = 1;
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    for (int i = 0; i < 10; i++) {
        st[id][i] = st[id << 1][i] + st[id << 1|1][i];
    } 
}
 
void cycle(int id, int time) {
    for (int i = 0; i < 10; i++) {
        cnt[i] = st[id][i];
    }
    for (int i = 0; i < 10; i++) {
        st[id][(i + time) % 10] = cnt[i];
    }
}
 
void fix(int id) {
    if (lazy[id] != 0) {
        lazy[id << 1] += lazy[id];
        lazy[id << 1|1] += lazy[id];
        
        cycle(id << 1, lazy[id]);
        cycle(id << 1|1, lazy[id]);
        
        lazy[id] = 0;
    }
}
 
void update(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return;
    
    if (l >= u && r <= v) {
        lazy[id]++;
        cycle(id, 1);
        return;
    }
    
    int mid = (l + r) >> 1;
    fix(id);
    update(id << 1, l, mid, u, v);
    update(id << 1|1, mid + 1, r, u, v);
    
    for (int i = 0; i < 10; i++) {
        st[id][i] = st[id << 1][i] + st[id << 1|1][i];
    }
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    
    if (l >= u && r <= v) {
        int res = 0;
        for (int i = 0; i < 10; i++) res += i * st[id][i];
        return res;
    }
    
    int mid = (l + r) >> 1;
    fix(id);
    return get(id << 1, l, mid, u, v) + get(id << 1|1, mid + 1, r, u, v); 
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << '\n';
        update(1, 1, n, l, r);
    } 
    
    return 0;
}