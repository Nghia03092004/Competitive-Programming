#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 1e5 + 5;
 
struct Fenwick {
    int n;
    vector <int> f;
    Fenwick(int n): n(n), f(n + 1, 0) {}
    void set(int i) {
        for (; i >= 1; i -= i & (-i)) f[i]++;
    }
    int get(int i) {
        int rsl = 0;
        for (; i <= n; i += i & (-i)) rsl += f[i];
        return rsl;
    }
};
 
main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    Fenwick f(N);
    int rsl = 0;
    while (n--) {
        int x;
        cin >> x;
        rsl += f.get(x + 1);
        f.set(x);
    }
    
    cout << rsl;
    return 0;
}