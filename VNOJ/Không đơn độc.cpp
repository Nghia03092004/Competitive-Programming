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
 
const int maxN = 1e4 + 5;
const int maxK = 1e2 + 5;
const ll inf = 1e15;
int n, k, a[maxN], f[maxN], pos[maxN], cnt[maxN];
ll F[maxN], g[maxN][maxK << 1], sum[maxN];

void updCnt(int x, int v) {
    for (; x <= f[0]; x += x & -x)
        cnt[x] += v;
} 

int getCnt(int x) {
    int ans = 0;
    for (; x > 0; x -= x & -x) 
        ans += cnt[x];
    return ans;
}

void updSum(int x, ll v) {
    for (; x <= f[0]; x += x & -x) 
        sum[x] += v;
}

ll getSum(int x) {
    ll ans = 0ll;
    for (; x > 0; x -= x & -x) 
        ans += sum[x];
    return ans;
}

main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
       scanf("%d", &a[i]);
        f[++f[0]] = a[i];
    }

    sort(f + 1, f + f[0] + 1);
    f[0] = unique(f + 1, f + f[0] + 1) - f - 1;
    for (int i = 1; i <= n; ++i)
        pos[i] = lower_bound(f + 1, f + f[0] + 1, a[i]) - f;

    for (int j = k; j <= 2 * k; ++j) {
        ll Sum = 0ll;
        for (int i = 1; i <= f[0]; ++i)
            cnt[i] = sum[i] = 0;
        for (int i = 1; i <= j - 1; ++i) 
            updCnt(pos[i], 1), updSum(pos[i], a[i]), Sum += a[i];

        int order = (j + 1) / 2;
        for (int i = j; i <= n; ++i) {
            updCnt(pos[i], 1);
            updSum(pos[i], a[i]);
            Sum += a[i];

            int L = 1, R = f[0], x = 0;
            while (L <= R) {
                int mid = L + R >> 1;
                if (order <= getCnt(mid))
                    x = mid, R = mid - 1;
                else L = mid + 1;
            }

            ll cntN = getCnt(x - 1), cntL = j - getCnt(x);
            ll sumN = getSum(x - 1), sumL = Sum - getSum(x);
            g[i][j] = (ll) f[x] * cntN - sumN + sumL - (ll) f[x] * cntL;

            int p = i - j + 1;
            updCnt(pos[p], -1);
            updSum(pos[p], -a[p]);
            Sum -= a[p];
       }
    }

    for (int i = 1; i <= n; ++i) 
        F[i] = inf;
    for (int i = k; i <= n; ++i)
        for (int j = k; j <= min(i, 2 * k); ++j)
            F[i] = min(F[i], F[i - j] + g[i][j]);

    printf("%lld", F[n]);

    cerr << "Time elapsed: " << TIME << " s.\n";
}