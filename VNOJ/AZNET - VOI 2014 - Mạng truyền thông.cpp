#pragma GCC optimize("Ofast,fast-math")
#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define pow abcd
#define ii pair<int, int>
#define iiii pair<ii, ii>
#define st first.first
#define nd first.second
#define rd second.first
#define th second.second
#define el '\n';
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
 
const int maxN = 1e4 + 5, maxM = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = INT_MAX;

struct edge {
    int u, v, c;
};

int T, n, m, u, v, c, A, B, x, y;
int a[maxN], b[maxN], pa[maxN], rnk[maxN], dd[maxM];
edge e[maxM];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i) cin >> a[i];
    for (int i = 1; i <= n - 1; ++i) cin >> b[i];
    for (int i = 1; i <= m; ++i) 
        cin >> e[i].u >> e[i].v >> e[i].c;
    A = B = 0;
    for (int i = 1; i <= m; ++i) dd[i] = 0;
}

void reset() {
    for (int i = 1; i <= n; ++i)
        pa[i] = i, rnk[i] = 0;
}

int findset(int u) {
    return (pa[u] == u ? u : pa[u] = findset(pa[u]));
}

int check(edge e) {
    int u = findset(e.u);
    int v = findset(e.v);
    if (u == v) return 0;
    pa[v] = u;
    if (rnk[u] < rnk[v]) swap(rnk[u], rnk[v]);
    if (rnk[u] == rnk[v]) rnk[u]++;
    return 1;
}

main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    int T; cin >> T;
    while (T--) {
        init();
        reset();
        for (int i = 1; i <= m; ++i) 
            if (e[i].c == 1) A += check(e[i]);

        reset();
        for (int i = 1; i <= m; ++i)
            if (e[i].c == 2) B += check(e[i]);

        int sum = inf;
        for (int i = max(0, n - 1 - B); i <= min(A, n - 1); ++i)
            if (sum > a[i] + b[n - 1 - i]) {
                sum = a[i] + b [n - 1 - i];
                x = i;
            }
        y = n - 1 - x;

        for (int i = 1; i <= m; ++i) 
            if (e[i].c == 1) dd[i] = check(e[i]);

        reset();
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            if (dd[i]) cnt += check(e[i]);
        for (int i = 1; i <= m and cnt < x; ++i)
            if (e[i].c == 1 and !dd[i])
                cnt += (dd[i] = check(e[i]));
        for (int i = 1; i <= m; ++i) 
            if (e[i].c == 2) dd[i] = check(e[i]);
        for (int i = 1; i <= m; ++i)
            if (dd[i]) cout << i << ' ';
        cout << el;
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}