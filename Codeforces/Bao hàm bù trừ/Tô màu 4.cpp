#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
int n, m;
int x, y, u, v;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int sub(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

int get(int n) {
    return ((n * (n + 1) % mod) / 2) % mod;
}

int calc(int x, int y, int u, int v) {
    return mul(sub(get(u), get(x - 1)), sub(get(v), get(y - 1)));
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> x >> y >> u >> v;
    cout <<  sub(calc(1, 1, n, m), calc(x, y, u, v));
}


// #pragma GCC optimize("Ofast,O3,fast-math,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,avx,abm,popcnt,tune=native")
// #include<bits/stdc++.h>

// using namespace std;

// #define int long long
// const int mod = 1e9 + 7;

// int n, m;
// int x, y, u, v;

// main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     cin >> n >> m;
//     cin >> x >> y >> u >> v;

//     int Sum = (((m + 1) * (n + 1) % mod / 4) * (m * n) % mod)% mod;
//     int sum = (((x + u) * (y + v) % mod / 4) * ((u - x + 1) * (v - y + 1) % mod)) % mod;
//     cout << (Sum - sum + mod) % mod;

// }