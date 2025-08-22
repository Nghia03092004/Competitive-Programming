#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[maxN];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (a * b) % mod;
}

int pow(int a, int exp) {
    int ans = 1;
    for (; exp > 0; exp >>= 1, a = a * a % mod)
        if (exp & 1) ans = ans * a % mod;
    return ans;
}

// int pow(int a, int b) {
//     if (b == 1) return a;
//     int c = pow(a, b / 2);
//     if (b & 1)
//         return mul(c, mul(c, a));
//     else return mul(c, c);
// }

int C(int n, int k) {
    return mul(fact[n], pow(mul(fact[n - k], fact[k]), mod - 2));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i)
        fact[i] = mul(fact[i - 1], i);


    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << C(n, k) << '\n';
    }
}

// #include<bits/stdc++.h>

// using namespace std;

// #define int long long
// const int mod = 1e9 + 7;
// const int N = 1e6 + 5;
// int t;
// int f[N], vf[N];

// int sqr(int x) {
//     return x * x;
// }

// int pow(int a, int b) {
//     if (b == 0) return 1 % mod;
//     else 
//         if (b % 2 == 0) 
//             return sqr(pow(a, b / 2)) % mod;
//         else return a * (sqr(pow(a, b / 2)) % mod) % mod;
// }

// int C(int n, int k) {
//     return f[n] * vf[n - k] % mod * vf[k] % mod; 
// }



// main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
    
//     f[0] = 1;
//     for (int i = 1; i <= N; i++) 
//         f[i] = f[i - 1] * i % mod;
//     vf[0] = 1;
//     for (int i = 1; i <= N; i++) 
//         vf[i] = pow(f[i], mod - 2);
    
//     cin >> t;
//     while (t--) {
//         int n, k;
//         cin >> n >> k;
//         cout << C(n, k) << '\n';
//     }
    
//     return 0;
// }