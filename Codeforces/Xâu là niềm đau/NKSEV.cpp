#include<bits/stdc++.h>

using namespace std;

const int maxN = 3e5 + 5;
const int mod = 1337377;
int n, q;
string s;
int dp[maxN];

struct node {
    node *a[26];
    bool cnt;
    trie() {
        cnt = false;
        for (int i = 0; i <= 25; ++i)
            a[i] = NULL;
    }
};

node *root;

void Insert(string s) {
    node *p = root;
    reverse(s.begin(), s.end());
    for (auto v: s) {
        if (p -> a[v - 'a'] == NULL) 
            p -> a[v - 'a'] = new node();
        p = p -> a[v - 'a'];
    }
    p -> cnt = true;
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    root = new node();
    cin >> s;
    int m = s.size();
    s = '#' + s;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        Insert(s);
    }

    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        node *p = root;
        int j = i;
        while (j > 0 && p -> a[s[j] - 'a'] != NULL) {
            p = p -> a[s[j] - 'a'];
            if (p -> cnt == true)
                dp[i] = (dp[i] + dp[j - 1]) % mod;
            --j; 
        }
    }
    cout << dp[m];
}