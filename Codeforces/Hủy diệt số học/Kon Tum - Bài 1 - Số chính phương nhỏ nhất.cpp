#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 1e4 + 5;
int n, a[maxN];

bool isInArr(int x) {
    for (int i = 1; i <= n; ++i) 
        if (a[i] == x)
            return true;
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];

    int ans = 0;
    while (isInArr(ans * ans)) ++ans;
    cout << ans * ans;

    return 0;
}