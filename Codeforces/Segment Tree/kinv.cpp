#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9; //1e9 + 7;
const int N = 1e5 + 5;
int n, k, a[N], st[N << 2][12], dp[N][12];
 
void update(int id, int l, int r, int i, int val, int len) {
    if (i < l || i > r) return;
    if (l == r) {
        st[id][len] = val;
        return;
    } 
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val, len);
    update(id << 1|1, mid + 1, r, i, val, len);
    
    st[id][len] = (st[id << 1][len] + st[id << 1|1][len]) % mod;
}
 
int get(int id, int l, int r, int u, int v, int len) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id][len];
    
    int mid = (l + r) >> 1;
    return (get(id << 1, l, mid, u, v, len) + get(id << 1|1, mid + 1, r, u, v, len)) % mod; 
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        for (int j = 2; j <= k; j++) {
            dp[i][j] = get(1, 1, n, a[i] + 1, n, j - 1);
        }
        for (int j = 1; j <= k; j++) {
            update(1, 1, n, a[i], dp[i][j], j);
        }
    }
    cout << get(1, 1, n, 1, n, k);
    return 0;
}