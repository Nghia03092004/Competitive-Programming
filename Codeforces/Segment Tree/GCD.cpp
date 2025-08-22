#include<bits/stdc++.h>
using namespace std;
 
const int sup = -1e9;
const int N = 5e5 + 5;
int n, k, ans = sup, a[N], st[N << 2]; 
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    st[id] = __gcd(st[id << 1], st[id << 1|1]);
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -1;
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    int get1 = get(id << 1, l, mid, u, v);
    int get2 = get(id << 1|1, mid + 1, r, u, v);
    if (get1 == -1) return get2;
    if (get2 == -1) return get1;
    return __gcd(get1, get2);
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build (1, 1, n);
    
    for (int i = k; i <= n; i++) 
        ans = max(ans, get(1, 1, n, i - k + 1, i));
        
    cout << ans;
    return 0;
}