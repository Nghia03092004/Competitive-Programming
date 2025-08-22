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
#define el '\n';
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
 
const int maxN = 1e6 + 6;
const int mod = 1e9 + 9;

typedef struct Node {
    Node *L, *R;
    char c;
} *node;

node init(char c) {
    node a = new Node();
    a->c = c;
    a->L = a->R = nullptr;
    return a;
}

string number(string s) {
    string a, b;
    ll n = 0ll, i = s.size() - 1;
    while (s[i] != ' ') a = s[i--] + a;
    for (int i = 0; i < a.size(); ++i) n = n * 10ll + a[i] - '0';
    while (n) {
        b = char(n % 2 + '0') + b;
        n /= 2;
    }
    while (b.size() < 32) b = '0' + b;
    return b;
}

string change(string s) {
    string t;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ' and s[i + 1] == '=') break;
        if (s[i] == 'A') t = t + '&', i += 2;
        else if (s[i] == 'O') t = t + '|', i++;
        else if (s[i] == 'X') t = t + '^', i += 2;
        else t = t + s[i];
    }
    return t;
}

string suffix(string s) {
    string t;
    s = '(' + s + ')';
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') st.push(s[i]);
        else if ('a' <= s[i] and s[i] <= 'z') t = t + s[i];
        else if (s[i] == ' ') continue;
        else if (s[i] == ')') {
            for (;;) {
                char k = st.top();
                st.pop();
                if (k == '(') break;
                t = t + k;
            }
        } else {
            while (!st.empty() and st.top() != '(') {
                t = t + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    return t;
}

node Build_Binary_Tree(string s) {
    stack<node> st;
    for (int i = 0; i < s.size(); ++i) {
        node a = init(s[i]);
        if (s[i] < 'a' or s[i] > 'z') {
            a->R = st.top();
            st.pop();
            a->L = st.top();
            st.pop();
        }
        st.push(a);
    }
    return st.top();
}

#define f(x, y) dfs(a->L, x) * dfs(a->R, y) % mod


ll dfs(node a, int x) {
    if ('a' <= a->c && a->c <= 'z') return 1ll;
    if (a->c == '&')
        return x ? f(1,1) : ((f(1,0) + f(0,1)) % mod + f(0,0)) % mod;
    if (a->c == '|')
        return x ? ((f(1,0) + f(0,1)) % mod + f(1,1)) % mod : f(0,0);
    return x ? (f(1,0) + f(0,1)) % mod : (f(0,0) + f(1,1)) % mod;
}

int main() {

    int T;
    scanf("%d\n", &T); // below testNum has special char, so should use scanf("%d\n", &T) and dont use ios_base ...
    while (T--) {
        string s;
        getline(cin, s);
        string num = number(s);
        s = suffix(change(s));
        node root = Build_Binary_Tree(s);
        ll ans = 1ll;
        for (int i = 0; i < num.size(); ++i)
        ans = (ans * dfs(root, num[i]-'0')) % mod;
        printf("%lld\n", ans);
    }

    return 0;
} 

// CP is a game and I'm a player!!!

