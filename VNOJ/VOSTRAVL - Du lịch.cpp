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
 
#define pow abcd
#define ii pair<int, int>
#define iiii pair<ii, ii>
#define el '\n';
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
 
const int maxN = 5e6 + 6;

int n, m, s, k, a[maxN], dd[maxN], deg[maxN], res[maxN], cnt;
vector<int> ke[maxN], kt[maxN];
stack<int> st;

void dfs(int u) {
    dd[u] = 1;
    for (int i = 0; i < deg[u]; ++i) {
        int v = ke[u][i];
        if (!dd[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m >> s >> k;
    while (m--) {
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
        kt[u].push_back(1);
        kt[v].push_back(1);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= k; ++i) cin >> a[i];
    dfs(s);
    for (int i = 1; i <= k; ++i)
        if (!dd[a[i]]) {
            cout << "NIE";
            return 0;
        }
    cout << "TAK" << el;
    st.push(s);
    while (!st.empty()) {
        int u = st.top();
        bool flag = true;
        for (int i = 0; i < deg[u]; ++i) {
            int v = ke[u][i];
            if (kt[u][i] == 1) {
                kt[u][i] = 0;
                st.push(v);
                flag = false;
                break;
            }
        }
        if (flag) {
            res[++cnt] = u;
            st.pop();
        }
    } 
    cout << cnt << ' ';
    for (int i = 1; i <= cnt; ++i) cout << res[i] << ' ';

    cerr << "Time elapsed: " << TIME << " s.\n";
}