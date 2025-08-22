#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
int n, a[N], st[4 * N];
long long ans = 0;
 
void update(int id, int l, int r, int i) {
    if (i < l || i > r) return;
    if (l == r) {
        st[id]++;
        return;
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i);
    update(id << 1|1, mid + 1, r, i);
    st[id] = st[id << 1] + st[id << 1|1];
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1|1, mid + 1, r, u, v);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += get(1, 1, n, a[i] + 1, n);
        update(1, 1, n, a[i]);
    }
    cout << ans;
}