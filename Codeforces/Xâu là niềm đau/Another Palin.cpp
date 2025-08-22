#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define pow abcd

const int mod = 1e9 + 7;
const int base = 311;
const int maxN = 1e5 + 5;

int n;
char s[maxN];
int pow[maxN + 5], pref[maxN], suff[maxN];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int sub(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

int getP(int l, int r) {
    return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
}

int getS(int l, int r) {
    return sub(suff[l], mul(suff[r + 1], pow[r - l + 1]));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> s[i];

    pow[0] = 1;
    for (int i = 1; i <= n; ++i) 
        pow[i] = mul(pow[i  - 1], base);

    for (int i = 1; i <= n; ++i)
        pref[i] = add(mul(pref[i - 1], base), s[i]);

    for (int i = n; i >= 1; --i)
        suff[i] = add(mul(suff[i + 1], base), s[i]);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = n, even = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (i - mid + 1 > 0 && i + mid <= n &&
                 getP(i - mid + 1, i) == getS(i + 1, i + mid)) 
            {
                l = mid + 1;
                even = mid;
            } else 
                r = mid - 1;
        }
        ans += even;

        l = 1, r = n;
        int odd = 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (i - mid > 0 && i + mid <= n &&
                getP(i - mid, i - 1) == getS(i + 1, i + mid)) 
            {
                l = mid + 1;
                odd = mid + 1;
            } else
                r = mid - 1;
        }
        ans += odd;
    }

    cout << ans;    
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
// const int maxN = 1e5 + 5;

// int n;
// char s[maxN];
// iiii pow[maxN + 5];
// iiii pref[maxN], suff[maxN];

// iiii add(iiii a, iiii b) {
//     return {{(a.st + b.st) % mod.st, (a.nd + b.nd) % mod.nd}, {(a.rd + b.rd) % mod.rd, (a.th + b.th) % mod.th}};
// }

// iiii mul(iiii a, iiii b) {
//     return {{(a.st * b.st) % mod.st, (a.nd * b.nd) % mod.nd}, {(a.rd * b.rd) % mod.rd, (a.th * b.th) % mod.th}};
// }

// iiii sub(iiii a, iiii b) {
//     return {{((a.st - b.st) % mod.st + mod.st) % mod.st, ((a.nd - b.nd) % mod.nd + mod.nd) % mod.nd}, {((a.rd - b.rd) % mod.rd + mod.rd) % mod.rd, ((a.th - b.th) % mod.th + mod.th) % mod.th}};
// }

// iiii getP(int l, int r) {
//     return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
// }

// iiii getS(int l, int r) {
//     return sub(suff[l], mul(suff[r + 1], pow[r - l + 1]));
// }

// main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0); cout.tie(0);

//     cin >> n;
//     for (int i = 1; i <= n; ++i) cin >> s[i];
 
//     pow[0] = {{1, 1}, {1, 1}};
//     for (int i = 1; i <= n; ++i)
//         pow[i] = mul(pow[i - 1], base);
 
//     for (int i = 1; i <= n; ++i) 
//         pref[i] = add(mul(pref[i - 1], base), {{s[i], s[i]}, {s[i], s[i]}});
 
//     for (int i = n; i >= 1; --i) 
//         suff[i] = add(mul(suff[i + 1], base), {{s[i], s[i]}, {s[i], s[i]}});

//     int ans = 0;
//     for (int i =  1; i <= n; ++i) {
//         int l = 1, r = n, even = 0;
//         while (l <= r) {
//             int mid = l + r >> 1;
//             if (i - mid + 1 >= 1 && i + mid <= n &&
//                 getP(i - mid + 1, i) == getS(i + 1, i + mid))
//             {
//                 l = mid + 1;
//                 even = mid;
//             } else r = mid - 1;
//         }
//         ans += even;
//         l = 1, r = n;
//         int odd = 1;
//         while (l <= r) {
//             int mid = l + r >> 1;
//             if (i - mid >= 1 && i + mid <= n && 
//                 getP(i - mid, i - 1) == getS(i + 1, i + mid))
//                 {
//                     l = mid + 1;
//                     odd = mid + 1; 
//                 } else r = mid - 1;
//         }
//         ans += odd;
//     } 

//     cout << ans;
//     return 0;
// }