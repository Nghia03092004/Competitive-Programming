#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 4e5 + 5;
struct Query {
    int c, d, L, R, id;
} q[N];
int n, m;
int a[N], ans[N], st[N << 2];
 
void update(int id, int l, int r, int i, int val) {
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
 
int walk(int id, int l, int r, int u, int v, int L) {
    if (l > v || r < u || st[id] >= L) return -1;
    
    if (l == r) return l;
    
    int mid = (l + r) >> 1;
    int left = walk(id << 1, l, mid, u, v, L);
    if (left == -1) return walk(id << 1|1, mid + 1, r, u, v, L);
    return left;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= m; i++) {
        cin >> q[i].c >> q[i].d >> q[i].L >> q[i].R;
        q[i].id = i;
    }
    
    sort(q + 1, q + m + 1, [](Query x, Query y) {
        return x.R < y.R;
    });
    
    int j = 1;
    for (int i = 1; i <= m; i++) {
        while (j <= q[i].R) {
            update(1, 1, n, a[j], j);
            j++;
        }
        ans[q[i].id] = walk(1, 1, n, q[i].c, q[i].d, q[i].L);
    } 
    
    for (int i = 1; i <= m; i++)  {
        if (ans[i] == -1) 
            cout << "OK";
        else cout << ans[i];
        cout << '\n';
    }
    
    
    return 0;
}