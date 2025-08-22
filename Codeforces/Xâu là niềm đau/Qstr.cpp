#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//#define int long long
#define pow abcd 
#define ii pair<int, int>
#define st first
#define nd second

const int maxN = (int) 1e6 + 5;
const int mod = (int) 1e9 + 7;
const ii base = ii(31, 71);
int n, m;
string s, t;
ii pow[maxN], prefS[maxN], prefT[maxN];

ii add(ii a, ii b) {
     return ii((a.st + b.st) % mod, (a.nd + b.nd) % mod);
}

ii mul(ii a, ii b) {
     return ii(1ll * a.st * b.st % mod, 1ll * a.nd * b.nd % mod);
}

ii sub(ii a, ii b) {
     return ii((a.st - b.st + mod) % mod, (a.st - b.st + mod) % mod);
}

int getHash(int l, int r, int type) {
     if (type == 1) {
          ii key1 = sub(prefS[r], mul(prefS[l - 1], pow[r - l + 1]));
          return ((key1.st << 30)|key1.nd);
     }
     ii key2 = sub(prefT[r], mul(prefT[l - 1], pow[r - l + 1]));
     return ((key2.st << 30)|key2.nd); 
}

signed main() {
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     cin >> n >> m;
     cin >> s >> t;
     s = '#' + s;
     t = '#' + t;

     pow[0] = ii(1, 1);
     for (int i = 1; i < maxN; ++i) 
          pow[i] = mul(pow[i - 1], base);

     for (int i = 1; i <= n; ++i) 
          prefS[i] = add(mul(prefS[i - 1], base), ii(s[i], s[i]));

     for (int i = 1; i <= m; ++i) 
          prefT[i] = add(mul(prefT[i - 1], base), ii(t[i], t[i]));
     
     int q; cin >> q;
     while (q--) {
          int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
          int l = 1, r = min(r1 - l1 + 1, r2 - l2 + 1), ans = 0;
          while (l <= r) {
               int mid = l + r >> 1;
               if (getHash(l1, l1 + mid - 1, 1) == getHash(l2, l2 + mid - 1, 2)) 
                    l = mid + 1, ans = mid;
               else 
                    r = mid - 1;
          }
          if (ans == min(r1 - l1 + 1, r2 - l2 + 1)) {
               if (r1 - l1 + 1 == r2 - l2 + 1)
                    cout << "=";
               else if (r1 - l1 + 1 > r2 - l2 + 1)
                    cout << ">";
               else 
                    cout << "<";
          }
          else {
               int x = l1 + ans;
               int y = l2 + ans;
               if (s[x] > t[y])
                    cout << ">";
               else cout << "<";
          }
     }
}


// #include<bits/stdc++.h>

// using namespace std;

// #define int long long 
// #define pow abcd
// #define ii pair<int, int>
// #define fi first
// #define se second

// const ii base = {311, 311};
// const ii mod = {1e9 + 7, 2e9 + 11};

// const int maxN = 1e6 + 5;

// int n, m;
// string s, t;
// ii pow[maxN], prefS[maxN], prefT[maxN];

// ii add(ii a, ii b) {
//     return {(a.fi + b.fi) % mod.fi, (a.se + b.se) % mod.se};
// }
 
// ii mul(ii a, ii b) {
//     return {(a.fi * b.fi) % mod.fi, (a.se * b.se) % mod.se};
// }
 
// ii sub(ii a, ii b) {
//     return {((a.fi - b.fi) % mod.fi + mod.fi) % mod.fi, ((a.se - b.se) % mod.se + mod.se) % mod.se};
// }

// ii get(int l, int r, int type) {
//     if (type == 1)
//         return sub(prefS[r], mul(prefS[l - 1], pow[r - l + 1]));
//     return sub(prefT[r], mul(prefT[l - 1], pow[r - l + 1]));
// }

// main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin >> n >> m;
//     cin >> s >> t;
//     s = '#' + s;
//     t = '#' + t;

//     pow[0] = {1, 1};
//     for (int i = 1; i < maxN; ++i) 
//         pow[i] = mul(pow[i - 1], base);

//     for (int i = 1; i <= n; ++i) 
//         prefS[i] = add(mul(prefS[i - 1], base), {s[i], s[i]});

//     for (int i = 1; i <= m; ++i) 
//         prefT[i] = add(mul(prefT[i - 1], base), {t[i], t[i]});

//     int q; cin >> q;
//     while (q--) {
//         int l1, r1, l2, r2;
//         cin >> l1 >> r1 >> l2 >> r2;
//         int l = 1, r = min(r1 - l1 + 1, r2 - l2 + 1), ans = 0;
//         while (l <= r) {
//             int mid = l + r >> 1;
//             if (get(l1, l1 + mid - 1, 1) == get(l2, l2 + mid - 1, 2))
//                 l = mid + 1, ans = mid;
//             else 
//                 r = mid - 1;
//         }
//         if (ans == min(r1 - l1 + 1, r2 - l2 + 1)) {
//             if (r1 - l1 + 1 == r2 - l2 + 1)
//                 cout << "=";
//             else if (r1 - l1 + 1 > r2 - l2 + 1)
//                 cout << ">";
//             else 
//                 cout << "<";
//         }
//         else {
//             int x = l1 + ans;
//             int y = l2 + ans;
//             if (s[x] > t[y])
//                 cout << ">";
//             else 
//                 cout << "<";
//         }
//     } 
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

// int n, m;
// string s, t;
// iiii pow[maxN];
// iiii prefS[maxN], prefT[maxN];

// iiii add(iiii a, iiii b) {
//     return {{(a.st + b.st) % mod.st, (a.nd + b.nd) % mod.nd}, {(a.rd + b.rd) % mod.rd, (a.th + b.th) % mod.th}};
// }

// iiii mul(iiii a, iiii b) {
//     return {{(a.st * b.st) % mod.st, (a.nd * b.nd) % mod.nd}, {(a.rd * b.rd) % mod.rd, (a.th * b.th) % mod.th}};
// }

// iiii sub(iiii a, iiii b) {
//     return {{((a.st - b.st) % mod.st + mod.st) % mod.st, ((a.nd - b.nd) % mod.nd + mod.nd) % mod.nd}, {((a.rd - b.rd) % mod.rd + mod.rd) % mod.rd, ((a.th - b.th) % mod.th + mod.th) % mod.th}};
// }

// iiii getS(int l, int r) {
//     return sub(prefS[r], mul(prefS[l - 1], pow[r - l + 1]));
// }

// iiii getT(int l, int r) {
//     return sub(prefT[r], mul(prefT[l - 1], pow[r - l + 1]));
// }

// main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0); cout.tie(0);

//     cin >> n >> m;
//     cin >> s >> t;
//     s = '#' + s;
//     t = '#' + t;
 
//     pow[0] = {{1, 1}, {1, 1}};
//     for (int i = 1; i <= n; ++i)
//         pow[i] = mul(pow[i - 1], base);
 
//     for (int i = 1; i <= n; ++i) 
//         prefS[i] = add(mul(prefS[i - 1], base), {{s[i], s[i]}, {s[i], s[i]}});
 
//     for (int i = 1; i <= m; ++i) 
//         prefT[i] = add(mul(prefT[i - 1], base), {{t[i], t[i]}, {t[i], t[i]}});
 
//     int q; cin >> q;
//     while (q--) {
//         int l1, r1, l2, r2;
//         cin >> l1 >> r1 >> l2 >> r2;
//         int l = 0, r = min(r1 - l1 + 1, r2 - l2 + 1), ans = 0;
//         while (l <= r) {
//             int mid = l + r >> 1;
//             if (getS(l1, l1 + mid - 1) == getT(l2, l2 + mid - 1))
//                 l = mid + 1, ans = mid;
//             else 
//                 r = mid - 1;
//         }
//         if (ans == min(r1 - l1 + 1, r2 - l2 + 1)) {
//             if (r1 - l1 + 1 == r2 - l2 + 1)
//                 cout << "=";
//             else if (r1 - l1 + 1 > r2 - l2 + 1)
//                 cout << ">";
//             else 
//                 cout << "<";
//         }
//         else {
//             int x = l1 + ans;
//             int y = l2 + ans;
//             if (s[x] > t[y])
//                 cout << ">";
//             else 
//                 cout << "<";
//         }
//     }
    
//     return 0;
// }