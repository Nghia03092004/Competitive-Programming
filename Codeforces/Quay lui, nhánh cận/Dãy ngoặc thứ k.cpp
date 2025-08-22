#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
int ans, n, cnt, k;
char a[310];

bool check() {
    int op = 0, cl = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) op++;
        else cl++;
        if (cl > op) return false;
    }
    return cl == op;
}

 
void print() {
    ans = true;
    for (int i = 0; i < n; i++) {
        if (a[i]) cout << ')';
        else cout << '(';
    }
}
 
void quaylui(int i) {
    if (i == n) {
        if (check()) cnt++;
        if (cnt == k) {
            print();
            exit(0);
        }
        return;
    }
    else {
        for (int j = 0; j <= 1; j++) {
            a[i] = j;
            quaylui(i + 1);
        }
    }
}
 
int main() {
    fast
    cin >> n >> k;
    quaylui(1);
    if (!ans) cout << -1;
    return 0;
}