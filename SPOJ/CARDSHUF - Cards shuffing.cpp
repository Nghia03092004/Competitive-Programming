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
 
#define int long long
#define pow abcd
#define ii pair<int, int>
#define iiii pair<ii, ii>
#define st first.first
#define nd first.second
#define rd second.first
#define th second.second
#define el '\n';
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
 
struct Node {
    Node *P, *L, *R;
    int sz, val;
};

typedef Node* PNode;

PNode root, nil;

void Update(PNode x) {
    x->sz = x->L->sz + x->R->sz + 1;
}

void SetL(PNode x, PNode y) {
    x->L = y;
    y->P = x;
}

void SetR(PNode x, PNode y) {
    x->R = y;
    y->P = x;
}

PNode NodeAt(PNode x, int i) {
    for (;;) {
        int p = x->L->sz + 1;
        if (i == p) break;
        if (i < p) x = x->L;
        else x = x->R, i -= p;
    }
    return x;
}

void UpTree(PNode x) {
    PNode y = x->P, z = y->P;
    if (y->L == x) SetL(y, x->R), SetR(x, y);
    else SetR(y, x->L), SetL(x, y);
    if (z->L == y) SetL(z, x);
    else SetR(z, x);
    Update(y); Update(x);
}

void Splay(PNode x) {
    for (;;) {
        PNode y = x->P, z = y->P;
        if (y == nil) return;
        if (z != nil) 
            if ((z->L == y) == (y->L == x)) UpTree(y);
            else UpTree(x);
        UpTree(x);
    }
}

void Split(PNode T, int i, PNode &T1, PNode &T2) {
    if (!i) {
        T1 = nil;
        T2 = T;
        return ;
    }
    T1 = NodeAt(T, i);
    Splay(T1);
    T2 = T1->R;
    T1->R = nil;
    T2->P = nil;
    Update(T1);
}

PNode Join(PNode T1, PNode T2) {
    if (T1 == nil) return T2;
    T1 = NodeAt(T1, T1->sz);
    Splay(T1);
    SetR(T1, T2);
    Update(T1);
    return T1;
}

const int maxN = 1e5 + 5;
int n, x, a[maxN], k, t[maxN];

void Init() {
    nil = new Node();
    nil->sz = nil->val = 0;
    nil->P = nil->L = nil->R = nil;
    root = nil;
}

PNode build(int l, int r) {
    if (l > r) return nil;
    int mid = l + r >> 1;
    PNode x = new Node();
    x->val = mid;
    x->P = nil;
    SetL(x, build(l, mid - 1));
    SetR(x, build(mid + 1, r));
    Update(x);
    return x;
}

void S(int i, int j) {
    PNode T1, T2, T3;
    Split(root, i - 1, T1, T2);
    Split(T2, 1, T2, T3);
    root = Join(T1, T3);
    Split(root, j - 1, T1, T3);
    root = Join(Join(T1, T2), T3);
}

void dfs(PNode x) {
    if (x == nil) return ;
    dfs(x->L);
    a[++a[0]] = x->val;
    dfs(x->R);
}

int get(int x) {
    int ans = 0;
    for (x; x > 0; x -= x & -x) ans = max(ans, t[x]);
    return ans;
}

void upd(int x, int f) {
    for (x; x <= n; x += x & -x) t[x] = max(t[x], f);
}

main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    cin >> n >> x;
    Init();
    root = build(1, n);

    while (x--) {
        int i, j; cin >> i >> j;
        S(i, j);
    }

    dfs(root);

    k = 1;
    for (int i = 1; i <= n; ++i) {
        int f = get(a[i]) + 1;
        upd(a[i], f);
        k = max(k, f);
    }

    cout << n - k;
    cerr << "Time elapsed: " << TIME << " s.\n";
}