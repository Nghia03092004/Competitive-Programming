#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int maxN = (int) 1e5 + 5;

int n, q, k;
int pre[maxN], a[maxN];

int f(int low) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) 
        if (a[i] <= low)
            sum += low - a[i];
    int y = k - sum;
    
    int l = a[1], r = a[n], high = a[n];
    while (l <= r) {
        int mid = l + r >> 1;
        int sum = 0;
        for (int i = 1; i <= n; ++i) 
            if (a[i] >= mid) {
                sum += a[i] - mid;
                if (sum > y) break;
            }
        if (sum <= y) 
            r = mid - 1, high = mid;
        else 
            l = mid + 1;
    } 
    return max((int) 0, high - low);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    sort(a + 1, a + n + 1);

    int l = a[1], r = a[n], ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int sum = 0;
        for (int i = 1; i <= n; ++i) 
            if (a[i] <= mid) {
                sum += mid - a[i];
                if (sum > k) 
                    break;
            }

        if (sum <= k) 
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }

    l = a[1], r = ans, ans = 0;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) > f(m2)) 
            l = m1 + 1, ans = m1;
        else 
            r = m2 - 1, ans = m2;
    }
    cout << f(ans);
}