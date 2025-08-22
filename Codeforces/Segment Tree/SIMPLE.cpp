#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
int n, q;
int st[26][N << 2];
int lazy[26][N << 2];
 
void fix(int t, int id,int l, int r) {
    if (!lazy[t][id]) return;
    
    int mid = (l + r) >> 1;
    lazy[t][id << 1] = lazy[t][id << 1|1] = lazy[t][id];
    st[t][id << 1] = (mid - l + 1) * (lazy[t][id] - 1);
    st[t][id << 1|1] = (r - mid) * (lazy[t][id] - 1);
    
    lazy[t][id] = 0; 
}
 
void update(int t, int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    
    if (l >= u && r <= v) {
        st[t][id] = (r - l + 1) * val;
        lazy[t][id] = val + 1;
        return;
    }
    
    int mid = (l + r) >> 1;
    fix(t, id, l, r);
    update(t, id << 1, l, mid, u, v, val);
    update(t, id << 1|1, mid + 1, r, u, v, val);
    
    st[t][id] = st[t][id << 1] + st[t][id << 1|1];
}
 
int get(int t, int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    
    if (l >= u && r <= v) return st[t][id];
    
    int mid = (l + r ) >> 1;
    fix(t, id, l, r);
    return get(t, id << 1, l, mid, u, v) + get(t, id << 1|1, mid + 1, r, u, v);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        update(c - 'a', 1, 1, n, i, i, 1);
    }
    
    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        
        if (k) {
            int id = i;
            for (int h = 0; h <= 25; h++) {
                int cnt = get(h, 1, 1, n, i, j);
                if (!cnt) continue;
                update(h, 1, 1, n, i, j, 0);
                update(h, 1, 1, n, id, id + cnt - 1, 1);
                id += cnt;
            }
        }
        else {
            int id = j;
            for (int h = 0; h <= 25; h++) {
                int cnt = get(h, 1, 1, n, i, j);
                if (!cnt) continue;
                update(h, 1, 1, n, i, j, 0);
                update(h, 1, 1, n, id - cnt + 1, id, 1);
                id -= cnt;
            }
        }
    }
    
        for (int i = 1; i <= n; i++) {
            for (int h = 0; h <= 25; h++) {
                if (get(h, 1, 1, n, i, i)) {
                    cout << char(h + 'a');
                    break;
                }
            }
        }
    
    
    return 0;
}