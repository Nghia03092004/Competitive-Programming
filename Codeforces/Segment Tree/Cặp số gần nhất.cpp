#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 5;
const int inf = 1e9;
 
struct Query {
    int l, r, id;
} q[N];
 
int n, m, a[N], st[N << 2], ans[N];
map <int, int> pos;
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = inf;
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    st[id] = inf;
} 
 
void update(int id, int l, int r, int i, int val) {
    if (i < l || i > r) return;
    if (l == r) {
        st[id] = min(st[id], val);
        return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1|1, mid + 1, r, i, val);
    
    st[id] = min(st[id << 1], st[id << 1|1]);
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return inf;
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, [](Query a, Query b) {return a.r < b.r;});
    
    int j = 1;
    for (int i = 1; i <= m; i++) {
        while (j <= n && j <= q[i].r) {
            if (pos[a[j]]) update(1, 1, n, pos[a[j]], j - pos[a[j]]);
            pos[a[j]] = j;
            j++;
        }
        ans[q[i].id] = get(1, 1, n, q[i].l, q[i].r);
    }
    
    for (int i = 1; i <= m; i++) 
        cout << (ans[i] == inf ? -1: ans[i]) << "\n";
    
    return 0;
}