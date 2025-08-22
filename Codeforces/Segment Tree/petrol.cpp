#pragma GCC optimize("Ofast,fast-math")
#include<bits/stdc++.h>
using namespace std;
 
#define ii pair<int, int> 
#define st first
#define nd second
 
const int inf = INT_MAX;
const int N = 1e5 + 5;
int n, st[N << 2], ans = 0, D;
ii a[N];
bool flag[N];
 
void build (int id, int l, int r) {
    if (l == r) {
        st[id] = a[l].nd;
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build (id << 1|1, mid + 1, r);
    
    st[id] = max(st[id << 1], st[id << 1|1]); 
}
 
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -inf;
    
    if (l >= u && r <= v) return st[id];
 
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> D;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].st >> a[i].nd;
    }
    sort(a + 1, a + n + 1);
    build(1, 1, n);
    
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (a[j].st < a[i].st - D) j++;
        if (get(1, 1, n, j, i - 1) >= 2 * a[i].nd) flag[i] = true;
    }
    
    j = n;
    for (int i = n; i >= 1; i--) {
        while (a[j].st > a[i].st + D) j--;
        if (flag[i] && get(1, 1, n, i + 1, j) >= 2 * a[i].nd) ans++; 
    }
    
    cout << ans;
    
    return 0;
}