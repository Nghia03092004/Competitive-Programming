#include<bits/stdc++.h>

using namespace std;


#define int long long
#define pow abcd 
#define ii pair<int, int>
#define fi first
#define se second

const int maxN = 2e3 + 5;
const ii mod = {1e9 + 7, 998224353};
const ii base = {311, 311};

int n, k;
string s;
ii pow[maxN];
ii pref[maxN];
bool cnt[300];
vector<ii> Hash;

ii add(ii a, ii b) {
    return {(a.fi + b.fi) % mod.fi, (a.se + b.se) % mod.se};
}

ii mul(ii a, ii b) {
    return {(a.fi * b.fi) % mod.fi, (a.se * b.se) % mod.se};
}

ii sub(ii a, ii b) {
    return {((a.fi - b.fi) % mod.fi + mod.fi) % mod.fi, ((a.se - b.se) % mod.se + mod.se) % mod.se};
}

ii get(int l, int r) {
    return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    s = '#' + s;

    pow[0] = {1, 1};
    for (int i = 1; i <= n; ++i)
        pow[i] = mul(pow[i - 1], base);

    for (int i = 1; i <= n; ++i) 
        pref[i] = add(mul(pref[i - 1], base), {s[i], s[i]});

    for (int i = 'a'; i <= 'z'; ++i) {
        char c; cin >> c;
        if (c == '0')
            cnt[i] = true;
    }

    cin >> k;

    for (int l = 1; l <= n; ++l) {
        int dem = 0;
        for (int r = l; r <= n; ++r) {
            dem += cnt[s[r]];
            if (dem <= k) 
                Hash.push_back(get(l, r));
        }
    }

    int ans = 0;
    sort(Hash.begin(), Hash.end());
    for (int i = 0; i < Hash.size(); ++i) {
        if (i == 0 || Hash[i] != Hash[i - 1]) 
            ++ans;
    }
    cout << ans;
    return 0;
}


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

// int n, k;
// string s;
// iiii pow[maxN];
// iiii pref[maxN];
// bool cnt[300];
// vector<iiii> Hash;

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

//     cin >> s;
//     n = s.size();
//     s = '#' + s;
 
//     pow[0] = {{1, 1}, {1, 1}};
//     for (int i = 1; i <= n; ++i)
//         pow[i] = mul(pow[i - 1], base);
 
//     for (int i = 1; i <= n; ++i) 
//         pref[i] = add(mul(pref[i - 1], base), {{s[i], s[i]}, {s[i], s[i]}});
 
//     for (int i = 'a'; i <= 'z'; ++i) {
//         char c; cin >> c;
//         if (c == '0')
//             cnt[i] = true;
//     }
 
//     cin >> k;
 
//     for (int l = 1; l <= n; ++l) {
//         int dem = 0;
//         for (int r = l; r <= n; ++r) {
//             dem += cnt[s[r]];
//             if (dem <= k) 
//                 Hash.push_back(get(l, r));
//         }
//     }
 
//     int ans = 0;
//     sort(Hash.begin(), Hash.end());
//     for (int i = 0; i < Hash.size(); ++i) {
//         if (i == 0 || Hash[i] != Hash[i - 1]) 
//             ++ans;
//     }
//     cout << ans;
//     return 0;
// }