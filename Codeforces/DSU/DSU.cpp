#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 5e5 + 5;
int n, m;
int par[maxN];

int acs(int u) {
    return u == par[u] ? u : par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) par[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) par[i] = i;

    while (m--) {
        char c; int u, v;
        cin >> c >> u >> v;
        if (c == '+')
            join(u, v);
        else {
            if (acs(u) == acs(v)) 
                cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
     }
}