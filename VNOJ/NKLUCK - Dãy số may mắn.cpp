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
 
const int maxN = 1e6 + 1e3;
int n, X, x[maxN], a[maxN], f[maxN], b[maxN], t[2][maxN];
ll ans;

void update(int x, int w) {
    for (x; x <= a[0]; x += x & -x) t[w][x]++;
}

ll get(int x, int w) {
    ll ret = 0;
    for (x; x > 0; x -= x & -x) ret += t[w][x];
    return ret;
}

ll calc(int k, int w) {
    ll res = 0;
    f[0] = a[0] = b[0] = 0;

    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + (x[i] >= k);
        b[++b[0]] = 2 * f[i] - i - 1;
        b[++b[0]] = 2 * f[i - 1] - i;
    }

    sort(b + 1, b + b[0] + 1);
    b[++b[0]] = maxN;
    for (int i = 1; i < b[0]; ++i) 
        if (b[i] < b[i + 1]) a[++a[0]] = b[i];

    for (int j = 1;  j <= n; ++j) {
        int x; 
        x = lower_bound(a + 1, a + a[0] + 1, 2 * f[j - 1] - j) - a;
        update(x, w);
        x = lower_bound(a + 1, a + a[0] + 1, 2 * f[j] - j - 1) - a;
        res += get(x, w);
    }
    return res;
}

main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> X;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    ans = calc(X, 0) - calc(X + 1, 1);
    cout << fixed << setprecision(6) << (double)ans / ((double)n*(n + 1)/2); 

    cerr << "Time elapsed: " << TIME << " s.\n";
}