#pragma GCC optimize("Ofast,fast-math")
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
int n;
pair <int, int> a[N];
int b[N], dp[N], st[4 * N];
 
void update(int id, int l, int r, int i, int val) {
    if (i > r || i < l) return;
    
    if (l == r) {
        st[id] = max(st[id], val);
        return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1|1, mid + 1, r, i, val);
    
    st[id] = max(st[id << 1], st[id << 1|1]);
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v)); 
} 
 
main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a + 1, a + n + 1);
    
    int id = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].first != a[i - 1].first) id++;
        b[a[i].second] = id;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = get(1, 1, n, 1, b[i]) + 1;
        ans = max(ans, dp[i]);
        update(1, 1, n, b[i], dp[i]);
    }
    
    cout << ans;
    return 0;
}