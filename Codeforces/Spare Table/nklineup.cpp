#include<bits/stdc++.h>
 
using namespace std;
 
const int maxN = 2e5 + 5;
int n, q;
int a[maxN], mi[20][maxN], ma[20][maxN];
 
int lg(int i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
 
int get(int l, int r, int t) {
    int k = lg(r - l + 1);
    if (t) return max(ma[k][l], ma[k][r - (1 << k) + 1]);
    return min(mi[k][l], mi[k][r - (1 << k) + 1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mi[0][i] = ma[0][i] = a[i];
    }
 
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]);
            ma[i][j] = max(ma[i - 1][j], ma[i - 1][j + (1 << (i - 1))]);
        }
    }
 
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(l, r, 1) - get(l, r, 0) << '\n';
    }
}