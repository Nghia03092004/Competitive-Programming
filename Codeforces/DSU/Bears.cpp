#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int, int> 
#define st first
#define nd second

const int maxN = (int) 1e5 + 5;
int n;
ii b[maxN];
int a[maxN], par[maxN], sz[maxN];
bool flag[maxN];
int perfect[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
} 

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        par[y] = x;
        sz[x] += sz[y];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b + 1, b + n + 1, [] (ii x, ii y)
        {
            return x.st > y.st;
        });

    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
        flag[i] = false;
    }
    
    perfect[0] = 1;
    for (int i = 1; i <= n; ++i) {
        flag[b[i].nd] = true;
        perfect[i] = perfect[i - 1];
        if (flag[b[i].nd + 1] && b[i].nd + 1 <= n) {
            join(b[i].nd, b[i].nd + 1);
            perfect[i] = max(sz[acs(b[i].nd)], perfect[i - 1]);
        }
        if (flag[b[i].nd - 1] && b[i].nd - 1 >= 1) {
            join(b[i].nd, b[i].nd - 1);
            perfect[i] = max(sz[acs(b[i].nd)], perfect[i - 1]);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = n, res = 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (perfect[mid] >= i) 
                r = mid - 1, res = b[mid].st;
            else
                l = mid + 1;
        }
        cout << res << ' ';
    }
}