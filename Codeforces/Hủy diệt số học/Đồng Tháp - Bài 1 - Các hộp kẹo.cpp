#include<bits/stdc++.h>

using namespace std;

#define int long long 

int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int i = 1, res = 0; 
    while (n >= 0) {
        if (n - i * i < 0) break;
        n -= i * i;
        ++i, ++res;
    }
    cout << res;
}