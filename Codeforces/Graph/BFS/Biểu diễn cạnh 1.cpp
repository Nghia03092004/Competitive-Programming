#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e3 + 5;
int n, m;
int a[maxN][maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) 
            cout << a[i][j] << " \n"[j == n];
    }
}