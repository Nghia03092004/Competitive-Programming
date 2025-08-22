#include<bits/stdc++.h>

using namespace std;

#define int __int128

const int maxN = (int) 2e5 + 5;
long long q, n;
int pre_c[maxN], pre_hc[maxN];
pair<int, int> a[maxN];

int get_c(int l, int r) {
    return pre_c[r] - pre_c[l - 1];
}

int get_hc(int l, int r) {
    return pre_hc[r] - pre_hc[l - 1];
}

int f(int id, int n) {
    return a[id].first * get_c(1, id) - get_hc(1, id)
        + get_hc(id + 1, n) - a[id].first * get_c(id + 1, n);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        a[i].first = x;
    }
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        a[i].second = x;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        pre_c[i] = pre_c[i - 1] + a[i].second;
        pre_hc[i] = pre_hc[i - 1] + a[i].second * a[i].first;
    }

    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i, ans = -1;
        while (l <= r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;

            if (f(m1, i) < f(m2, i)) 
                r = m2 - 1, ans = m2;
            else 
                l = m1 + 1, ans = m1;
        }

        int p = f(ans, i);
        vector<long long> res;

        if (p == 0) 
            res.push_back(0);

        while (p) {
            res.push_back(p % 10);
            p /= 10;
        }

        reverse(res.begin(), res.end());

        for (auto v: res) 
            cout << v;
        cout << " ";
    }
    cout << '\n';
}