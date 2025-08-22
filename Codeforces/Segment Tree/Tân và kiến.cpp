#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
 
using namespace std;
 
const int maxN = 3e5 + 5;
int n;
int a[maxN], gcdST[maxN << 2];
pair<int, int> minST[maxN << 2];
 
void build(int id, int l, int r) {
    if (l == r) {
        gcdST[id] = a[l];
        minST[id] = {a[l], 1};
        return;
    }
    
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1|1, mid + 1, r);
    
    gcdST[id] = __gcd(gcdST[id << 1], gcdST[id << 1|1]);
    if (minST[id << 1].first == minST[id << 1|1].first) 
        minST[id] = {minST[id << 1].first, minST[id << 1].second + minST[id << 1|1].second};
    else minST[id] = min(minST[id << 1], minST[id << 1|1]);
}
 
int getGCD(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return a[u];
    
    if (l >= u && r <= v) return gcdST[id];
    
    int mid = (l + r) >> 1;
    return __gcd(getGCD(id << 1, l, mid, u, v), getGCD(id << 1|1, mid + 1, r, u, v));
}
 
 
pair<int, int> getMIN(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return {0, 0};
    
    if (l >= u && r <= v) return minST[id];
    
    int mid = (l + r) >> 1;
    pair<int, int> left = getMIN(id << 1, l, mid, u, v);
    pair<int, int> right = getMIN(id << 1|1, mid + 1, r, u, v);
    if (!left.second) return right;
    if (!right.second) return left;
    if (left.first == right.first) 
        return {left.first, left.second + right.second};
    else return min(left, right);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        pair<int, int> mn = getMIN(1, 1, n, l, r);
        if (mn.first == getGCD(1, 1, n, l, r)) 
            cout << r - l + 1 - mn.second;
        else cout << r - l + 1  ;
        cout << '\n';
    }
}