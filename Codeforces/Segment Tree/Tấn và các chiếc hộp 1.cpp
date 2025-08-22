#include<bits/stdc++.h>
using namespace std;
 
const int inf = INT_MAX;
const int N = 3e5 + 5;
int n, q;
bool check;
multiset <int> st[N << 2];
 
void update(int id, int l, int r, int i, int val, int type) {
    if (i < l || i > r) return;
    
    if (l == r) {
        if (type == 1) {
            st[id].insert(val);
            return;
        } else {
            auto it = st[id].find(val);
            if (it != st[id].end()) {
                st[id].erase(it);
                check = true;
            }
            return;
        }
    }
    
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val, type);
    update(id << 1|1, mid + 1, r, i, val, type);
    
    if (type == 1) {
        st[id].insert(val);
    } else {
        auto it = st[id].find(val);
        if (it != st[id].end() && check)
            st[id].erase(it);
        return;
    }
}
 
int get(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return inf;
    
    if (l >= u && r <= v) {
        auto it = st[id].upper_bound(val);
        return (it != st[id].end() ? *(it) : inf);
    }
    
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v, val), get(id << 1|1, mid + 1, r, u, v, val));
}
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> q;
    while (q--) {
        int type, pos, l, r, val;
        cin >> type;
        if(type == 1) {
            cin >> pos >> val;
            update(1, 1, n, pos, val, 1);
        } else if (type == 2) {
            check = false;
            cin >> pos >> val;
            update(1, 1, n, pos, val, 2);
        } else {
            cin >> l >> r >> val;
            int ans = get(1, 1, n, l, r, val);
            (ans != inf) ? cout << ans :  cout << "NONE";
            cout << '\n';
        }
    }
}