#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 7e2 + 5;
int n, a[N][N], st[N << 2];
vector<pair<int, int>> b[N * N];
int f[N * N], g[N * N];
int ans[N << 1];
 
void update(int id, int l, int r, int i, int val) {
    if (i < l || i > r) return;
    
    if (l == r) {
        st[id] = max(st[id], val);
        return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1|1, mid + 1, r, i, val);
    
    st[id] = max(st[id << 1], st[id << 1|1]);
}
 
void updateMARK(int id, int l, int r, int i, int val) {
    if (i < l || i > r) return;
    
    if (l == r) {
        st[id] = val;
        return;
    }
    
    int mid = (l + r) >> 1;
    updateMARK(id << 1, l, mid, i, val);
    updateMARK(id << 1|1, mid + 1, r, i, val);
    
    st[id] = max(st[id << 1], st[id << 1|1]);
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[a[i][j]].push_back({i, j});
        }
    }
    
    for (int x = 1; x <= n * n; x++) {
        sort(b[x].begin(), b[x].end());
        
        for (int i = 0; i < b[x].size(); i++) 
            f[i] = g[i] = 0;
            
        for (int i = 0; i < b[x].size(); i++) {
            f[i] = get(1, 1, n, 1, b[x][i].second) + 1;
            update(1, 1, n, b[x][i].second, f[i]);
        }
        
        for (int i = 0; i < b[x].size(); i++)
            updateMARK(1, 1, n, b[x][i].second, 0);
            
        for (int i = b[x].size() - 1; i >= 0; i--) {
            g[i] = get(1, 1, n, b[x][i].second, n) + 1;
            update(1, 1, n, b[x][i].second, g[i]);
        }
        
        for (int i = 0; i < b[x].size(); i++) 
            updateMARK(1, 1, n, b[x][i].second, 0);
            
        for (int i = 0; i < b[x].size(); i++)
            ans[f[i] + g[i] - 1]++;
    }
    
    for (int i = 1; i <= 2 * n - 1; i++) 
        cout << ans[i] << '\n';
        
    return 0;
}