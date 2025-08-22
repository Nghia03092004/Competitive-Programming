#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define pow abcd

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
const int base = 311;
string s, t;
int hashT = 0;
int pref[maxN], pow[maxN];


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
    if (l > r) return 0;
    return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> t;

    pow[0] = 1;
    for (int i = 1; i <= maxN; ++i)
        pow[i] = mul(pow[i - 1], base);

    s = '#' + s;
    for (int i = 1; i < s.size(); ++i) 
        pref[i] = add(mul(pref[i - 1], base), s[i]);

    for (int i = 0; i < t.size(); ++i)
        hashT = add(mul(hashT, base), t[i]);

    for (int i = 1; i + t.size() - 1 < s.size(); ++i)
        if (get(i, i + t.size() - 1) == hashT)
            cout << i << ' ';
}


// #include<bits/stdc++.h>

// using namespace std;

// #define int long long
// #define pow abcd
// #define ii pair<int, int>
// #define iii pair<ii, int>
// #define st first.first
// #define nd first.second
// #define rd second

// const iii base = {{311, 311}, 311};
// const iii mod = {{1e9 + 7, 998224353}, (int)2e9 + 11};
// const int maxN = 1e6 + 5;

// string s, t;
// iii pow[maxN], pref[maxN];

// iii add(iii a, iii b) {
//     return {{(a.st + b.st) % mod.st, (a.nd + b.nd) % mod.nd}, (a.rd + b.rd) % mod.rd};
// }

// iii mul(iii a, iii b) {
//     return {{(a.st * b.st) % mod.st, (a.nd * b.nd) % mod.nd}, (a.rd * b.rd) % mod.rd};
// }

// iii sub(iii a, iii b) {
//     return {{((a.st - b.st) % mod.st + mod.st) % mod.st, ((a.nd - b.nd) % mod.nd + mod.nd) % mod.nd}, ((a.rd - b.rd) % mod.rd + mod.rd) % mod.rd};
// }

// iii get(int l, int r) {
//     return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
// }

// main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0); cout.tie(0);

//     cin >> s >> t;
//     s = '#' + s;

//     pow[0] = {{1, 1}, 1};
//     for (int i = 1; i <= maxN; ++i) 
//         pow[i] = mul(pow[i - 1], base);

//     for (int i = 1; i < s.size(); ++i) 
//         pref[i] = add(mul(pref[i - 1], base), {{s[i], s[i]}, s[i]});

//     int k = t.size();
//     iii hashT = {{0, 0}, 0};
//     for (int i = 0; i < k; ++i)
//         hashT = add(mul(hashT, base), {{t[i], t[i]}, t[i]});

//     for (int i = 1; i + k - 1 < s.size(); ++i) {
//         if (get(i, i + k - 1) == hashT) 
//             cout << i << ' ';
//     }

//     return 0;
// }


// #include<bits/stdc++.h>

// using namespace std;

// #define int long long
// #define pow abcd
// #define ii pair<int, int>
// #define iiii pair<ii, ii>
// #define st first.first
// #define nd first.second
// #define rd second.first
// #define th second.second

// const iiii base = {{311, 311}, {311, 311}};
// const iiii mod = {{1e9 + 7, 998224353}, {2e9 + 11, 2147483647}};
// const int maxN = 1e6 + 5;

// string s, t;
// iiii pow[maxN], pref[maxN];

// iiii add(iiii a, iiii b) {
//     return {{(a.st + b.st) % mod.st, (a.nd + b.nd) % mod.nd}, {(a.rd + b.rd) % mod.rd, (a.th + b.th) % mod.th}};
// }

// iiii mul(iiii a, iiii b) {
//     return {{(a.st * b.st) % mod.st, (a.nd * b.nd) % mod.nd}, {(a.rd * b.rd) % mod.rd, (a.th * b.th) % mod.th}};
// }

// iiii sub(iiii a, iiii b) {
//     return {{((a.st - b.st) % mod.st + mod.st) % mod.st, ((a.nd - b.nd) % mod.nd + mod.nd) % mod.nd}, {((a.rd - b.rd) % mod.rd + mod.rd) % mod.rd, ((a.th - b.th) % mod.th + mod.th) % mod.th}};
// }

// iiii get(int l, int r) {
//     return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
// }

// main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0); cout.tie(0);

//     cin >> s >> t;
//     s = '#' + s;

//     pow[0] = {{1, 1}, {1, 1}};
//     for (int i = 1; i <= maxN; ++i) 
//         pow[i] = mul(pow[i - 1], base);

//     for (int i = 1; i < s.size(); ++i) 
//         pref[i] = add(mul(pref[i - 1], base), {{s[i], s[i]}, {s[i], s[i]}});

//     int k = t.size();
//     iiii hashT = {{0, 0}, {0, 0}};
//     for (int i = 0; i < k; ++i)
//         hashT = add(mul(hashT, base), {{t[i], t[i]}, {t[i], t[i]}});

//     for (int i = 1; i + k - 1 < s.size(); ++i) {
//         if (get(i, i + k - 1) == hashT) 
//             cout << i << ' ';
//     }

//     return 0;
// }