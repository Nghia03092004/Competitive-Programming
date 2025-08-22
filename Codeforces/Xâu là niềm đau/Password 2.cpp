#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pow abcd

const int base = 311;
const int mod = 998224353;
const int maxN = 1e5 + 5;

int n;
int pow[maxN], pref[maxN];
string s[maxN];
map<int, int> Hash[maxN];
set<int> lens;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int sub(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

int get(int l, int r) {
    return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    pow[0] = 1;
    for (int i = 1; i <= n; ++i) 
        pow[i] = mul(pow[i - 1], base);

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        int val = 0;
        for (auto k: s[i]) 
            val = add(mul(val, base), k);
        Hash[s[i].size()][val]++;
        lens.insert(s[i].size());
    }

    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for(auto len: lens)  {
            pref[0] = s[i][0];
            set<int> st;
            for (int j = 1; j < s[i].size(); ++j) {
                pref[j] = add(mul(pref[j - 1], base), s[i][j]);
            }

            for (int j = len - 1; j < s[i].size(); j++) {
                if (st.find(get(j - len + 1, j)) == st.end() && 
                    Hash[len].find(get(j - len + 1, j)) != Hash[len].end()) 
                {
                    ans += Hash[len][get(j - len + 1, j)];
                    st.insert(get(j - len + 1, j));
                }
            }
        }
        cout << ans - 1 << '\n';
    }
}