#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
const int N = 3e5 + 5;
const int M = 1e6 + 5;
int n, m, ans = inf;
pair<int, pair<int, int>> a[N];
int st[M << 2], lazy[M << 2];
 
void build(int id, int l, int r) {
    st[id] = -inf;
    if (l == r) return;
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
}
 
void fix(int id) {
    if (lazy[id]) {
        lazy[id << 1] = lazy[id];
        lazy[id << 1|1] = lazy[id];
        st[id << 1] = lazy[id];
        st[id << 1|1] = lazy[id];
        
        lazy[id] = 0;
    }
}
 
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return ;
    
    if (l >= u && r <= v) {
        lazy[id] = val;
        st[id] = val;
        return;
    }
    
    int mid = (l + r) >> 1;
    fix(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1|1, mid + 1, r, u, v, val);
    
    st[id] = min(st[id << 1], st[id << 1|1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second.first >> a[i].second.second >> a[i].first;
    }
    sort(a + 1, a + n + 1);
    build(1, 1, m - 1);
    
    for (int i = 1; i <= n; i++) {
        update(1, 1, m - 1, a[i].second.first, a[i].second.second - 1, a[i].first);
        ans = min(ans, a[i].first - st[1]);
    }   
    
    cout << ans;
    return 0;
}