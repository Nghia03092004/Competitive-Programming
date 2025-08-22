#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
const int maxN = 2e5 + 5;
 
int n, q, h[maxN], Min[maxN << 2], Max[maxN << 2];
 
void build(int id, int l, int r) {
    if (l == r) {
        Min[id] = h[l];
        Max[id] = h[l];
        return;
    }
 
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
 
    Min[id] = min(Min[id << 1], Min[id << 1|1]);
    Max[id] = max(Max[id << 1], Max[id << 1|1]);
}
 
int getMax(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -inf;
 
    if (u <= l && v >= r) return Max[id];
 
    int mid = (l + r) >> 1;
    return max(getMax(id << 1, l, mid, u, v), getMax(id << 1|1, mid + 1, r, u, v));
}
 
int getMin(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return inf;
 
    if (u <= l && v >= r) return Min[id];
 
    int mid = (l + r) >> 1;
    return min(getMin(id << 1, l, mid, u, v), getMin(id << 1|1, mid + 1, r, u, v));
}
 
main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    build(1, 1, n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getMax(1, 1, n, a, b) - getMin(1, 1, n, a, b) << '\n';
    }
    return 0;
}