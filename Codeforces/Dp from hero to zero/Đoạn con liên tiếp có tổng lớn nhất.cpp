#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e6 + 5;
int n;
int a[maxN];

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int best = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum = max(a[i], sum + a[i]);
        best = max(best, sum);
    }
    cout << best;
}

// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// const int N = 1e6;
// int n, a[N], dp[N];

// main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     dp[1] = a[1];
//     for (int i = 2; i <= n; i++) 
//         dp[i] = max(a[i], dp[i - 1] + a[i]);
//     cout << *max_element(dp + 1, dp + n + 1);
// }