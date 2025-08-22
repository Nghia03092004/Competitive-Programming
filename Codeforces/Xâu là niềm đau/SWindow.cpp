#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pow abcd
#define ii pair<int, int>
#define iiii pair<ii, ii>
#define st first.first
#define nd first.second
#define rd second.first
#define th second.second

const iiii base = {{311, 311}, {311, 311}};
const iiii mod = {{1e9 + 7, 998224353}, {2e9 + 11, 2147483647}};
const int maxN = 1e6 + 5;

int n, m, k;
string t, p;
iiii pow[maxN + 5];
iiii pref[maxN];
int g[maxN], f[maxN];


iiii add(iiii a, iiii b) {
    return {{(a.st + b.st) % mod.st, (a.nd + b.nd) % mod.nd}, {(a.rd + b.rd) % mod.rd, (a.th + b.th) % mod.th}};
}

iiii mul(iiii a, iiii b) {
    return {{(a.st * b.st) % mod.st, (a.nd * b.nd) % mod.nd}, {(a.rd * b.rd) % mod.rd, (a.th * b.th) % mod.th}};
}

iiii sub(iiii a, iiii b) {
    return {{((a.st - b.st) % mod.st + mod.st) % mod.st, ((a.nd - b.nd) % mod.nd + mod.nd) % mod.nd}, {((a.rd - b.rd) % mod.rd + mod.rd) % mod.rd, ((a.th - b.th) % mod.th + mod.th) % mod.th}};
}

iiii get(int l, int r) {
    return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
}

main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    getline(cin, t);
    n = t.size();
    t = '#' + t;

    getline(cin, p);
    m = p.size();
    p = '#' + p;

    cin >> k;
    pow[0] = {{1, 1}, {1, 1}};
    for (int i = 1; i <= n; ++i) 
        pow[i] = mul(pow[i - 1], base);

    for (int i = 1; i <= n; ++i)
        pref[i] = add(mul(pref[i - 1], base), {{t[i], t[i]}, {t[i], t[i]}}); 

    iiii hashP = {{0, 0}, {0, 0}};
    for (int i = 1; i <= m; ++i) 
        hashP = add(mul(hashP, base), {{p[i], p[i]}, {p[i], p[i]}});

    for (int i = m; i <= n; ++i) {
        if (get(i - m + 1, i) == hashP) {
            int l = i - k + 1;
            int r = i - m + 1;
            f[max((int)1, l)] += 1;
            f[min((int)n + 1, r + 1)] -= 1;
        }
    }

    int ans = 0;
    for (int i = 1; i + k - 1 <= n; ++i) {
        g[i] = g[i - 1] + f[i];
        if (g[i]) ++ans;
    }
    cout << ans;
}