#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define pow abc

const int base = 311;
const int mod = 1e9 + 7;
const int maxN = 1e6;

int n, k;
string s;
int pow[maxN + 5], pref[maxN];

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

bool check(int mid) {
    vector<int> Hash;
    for (int i = 1; i + mid - 1 <= n; ++i) {
        int x = get(i, i + mid - 1);
        Hash.push_back(x);
    }
    sort(Hash.begin(), Hash.end());
    int cnt = 0;
    for (int i = 0; i < Hash.size(); ++i) {
        if (i == 0 || Hash[i] == Hash[i - 1]) 
            ++cnt;
        else cnt = 1;
        if (cnt >= k) return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> s;

    pow[0] = 1;
    for (int i = 1; i <= n; ++i) 
        pow[i] = mul(pow[i - 1], base);

    s = '#' + s;
    for (int i = 1; i <= n; ++i) 
        pref[i] = add(mul(pref[i - 1], base), s[i]);

    int l = 1, r = n, ans(0);
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid; 
            l = mid + 1;
        } else r = mid - 1;
    } 

    cout << ans;
}


// #include<bits/stdc++.h>

// using namespace std;

// #define int long long 
// #define pow abcd

// const int base = 311;
// const int maxN = 1e5;
// const int mod = 1e9 + 7;
// int n, k;
// string s;
// int pow[maxN + 5], pref[maxN + 5];

// int add(int a, int b) {
//     return (a + b) % mod;
// }

// int mul(int a, int b) {
//     return (a * b) % mod;
// }

// int sub(int a, int b) {
//     return ((a - b) % mod + mod) % mod;
// }

// int get(int l, int r) {
//     if (l > r) return 0;
//     return sub(pref[r], mul(pref[l - 1], pow[r - l + 1]));
// }

// bool check(int mid) {
//     map<int, int> cnt;
//     for (int i = 1; i + mid - 1 <= n; ++i) {
//         int x = get(i, i + mid - 1);
//         cnt[x]++;
//         if (cnt[x] >= k) return true;
//     }
//     return false;
// }

// main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin >> n >> k >> s;

//     pow[0] = 1;
//     for (int i = 1; i <= maxN; ++i)
//         pow[i] = mul(pow[i - 1], base);

//     s = '#' + s;
//     for (int i = 1; i <= n; ++i) 
//         pref[i] = add(mul(pref[i - 1], base), s[i]);

//     int l = 1, r = n, ans = 0;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         if (check(mid)) {
//             l = mid + 1;
//             ans = mid;
//         } else r = mid - 1;
//     }

//     cout << ans;
//     return 0;
// }