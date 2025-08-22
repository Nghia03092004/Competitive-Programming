#include<bits/stdc++.h>

using namespace std;

#define int long long
const int maxN = 1e6 + 5;
int a[maxN], dp[maxN], pref[maxN];
int n, k, ans = -1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        dp[i] = -1e18;
    }
    for (int i =  1; i <= n; ++i)
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    for (int r = k; r <= n; ++r)
        ans = max({ans, pref[r] - pref[r - k], pref[r] - pref[r - k] + dp[r - k]});
    cout << ans;
}


#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 6;
int n, k, a[N], dp[N], b[N], ans = -1e18;

main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += a[i];
        if (i >= k) {
            b[i - k + 1] = tmp;
            tmp -= a[i - k + 1];
        }
    }
    for (int i = 1; i <= n; i++) 
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    for (int i = 1; i <= n - k + 1; i++)
        ans = max(ans, max(b[i], b[i] + dp[i - 1]));
    cout << ans;
}


#include<bits/stdc++.h>
using namespace std;

long long Max(long long a, long long b) {
    if (a > b) return a;
    return b;
}

const int N = 1e6 + 9;
int n, k;
long long a[N], f[N], dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    f[1] = a[1]; dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + a[i];
        dp[i] = Max(a[i], dp[i - 1] + a[i]);
    }
    long long ans = -1e18;
    for (int i = k; i <= n; i++) {
        ans = Max(ans, Max(f[i] - f[i - k], f[i] - f[i - k] + dp[i - k]));
    }
    cout << ans;
}


#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int n, k;
long long  ans;
long long  a[N], t[N], dp[N];


//t[i] la tong cac phan tu tu 1 den i
//  
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[i] = t[i - 1] + a[i];
        dp[i] = min(t[i - 1], dp[i - 1]);
    }
    ans = t[k] - dp[1];
    for (int i = k + 1; i <= n; i++) 
        ans = max(t[i] - dp[i - k + 1], ans);
    cout << ans;
}