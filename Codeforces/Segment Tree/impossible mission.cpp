#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
 
using namespace std;
 
const int maxN = 1e5 + 5;
int n, m;
vector<pair<int, int>> q;
int a[maxN], b[maxN];
int st[maxN << 2], lazy[maxN << 2];
 
void fix(int id) {
    if (!lazy[id]) return;
    
    lazy[id << 1] = lazy[id];
    lazy[id << 1|1] = lazy[id];
    st[id << 1] = lazy[id];
    st[id << 1|1] = lazy[id];
    
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    
    if (l >= u && r <= v) {
        lazy[id] = val;
        st[id] = val;
        return;
    }
    
    int mid = (l + r) >> 1;
    fix(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1|1, mid + 1, r, u, v, val);
}
 
int get(int id, int l, int r, int i) {
    if (l == r) return st[id];
    
    int mid = (l + r) >> 1;
    fix(id);
    if (i <= mid) 
        return get(id << 1, l, mid, i);
    else return get(id << 1|1, mid + 1, r, i);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            q.push_back({x, y});
            update(1, 1, n, y, y + k - 1, q.size());
        }
        else {
            int x;
            cin >> x;
            int queryPos = get(1, 1, n, x);
            if (!queryPos) cout << b[x] << '\n';
            else cout << a[q[queryPos - 1].first + x - q[queryPos - 1].second] << '\n';
        }
    }
}