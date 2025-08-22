#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxN = 1e5 + 5;
int a[maxN], b[maxN], c[maxN];
int f1[maxN], f2[maxN], f3[maxN];
int n;

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i <= n; ++i) {
        f1[i] = min(f2[i - 1], f3[i - 1]) + a[i];
        f2[i] = min(f1[i - 1], f3[i - 1]) + b[i];
        f3[i] = min(f1[i - 1], f2[i - 1]) + c[i];
    }

    cout << min({f1[n], f2[n], f3[n]});
}
