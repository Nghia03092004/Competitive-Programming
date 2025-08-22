#include<bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
int n, cnt = 0, k;
char a[310];
 
bool check() {
    int op = 0, cl = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) op++;
        else cl++;
        if (cl > op) return false;
    }
    return cl == op;
}
 
 
void print() {
    for (int i = 1; i <= n; i++) {
        if (a[i]) cout << ')';
        else cout << '(';
    }
    cout << endl;
}

void Try(int i) {
	if (i > n) {
		if (check()) print();
	} else {
		for (int j = 0; j <= 1; j++) {
			a[i] = j;
			if (!a[i]) ++cnt;
			else cnt = 0;
			if (cnt > k) continue;
			Try(i + 1);
		}
	}
}
 
int main() {
    fast
    cin >> n >> k;
    Try(1);
}