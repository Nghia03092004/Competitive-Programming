#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define el '\n'

ll Sum(int n) {
    return 1ll * n * (n + 1) / 2; // calculate: Sum(n) = 1 + ... + n = n * (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        ll sum3 = 3ll * Sum((n - 1) / 3);
        ll sum5 = 5ll * Sum((n - 1) / 5);
        ll sum15 = 15ll * Sum((n - 1) / 15);
        cout << sum3 + sum5 - sum15 << el;
    }
}

// CP is a game and I'm a player.