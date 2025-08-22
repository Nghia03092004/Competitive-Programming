#include<bits/stdc++.h>
using namespace std;
 
#define ii pair <int, int> 
#define iiii pair <pair <int, int>, pair <int, int>>
#define st first
#define nd second
 
const int N = 3e4 + 5;
const int Q = 2e5 + 5;
int n, m, ans[Q], st[N << 2];
ii a[N];
iiii q[Q];
 
void update(int id, int l, int r, int i, int val) {
    if (i < l || i > r) return;
    
    if (l == r) {
        st[id] += val;
        return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1|1, mid + 1, r, i, val);
    
    st[id] = st[id << 1] + st[id << 1|1];
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0; 
    
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1|1, mid + 1, r, u, v);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].second.first >> q[i].second.second >> q[i].first.first;
        q[i].first.second = i;
    }
    
    sort(a + 1, a + n + 1);
    sort(q + 1, q + m + 1);
    
    int j = n;
    for (int i = m; i >= 1; i--) {
        while (j && a[j].first > q[i].first.first) {
            update(1, 1, n, a[j].second, 1);
            j--;
        } 
        ans[q[i].first.second] = get(1, 1, n, q[i].second.first, q[i].second.second);
    }
    
    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    
    return 0;
}