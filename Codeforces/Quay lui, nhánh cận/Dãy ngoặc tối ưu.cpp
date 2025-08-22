#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ii pair <int, int>
const int N = 3e2 + 10;
int ans = 1e9, n, cnt;
char a[N];
ii val[N];

bool check() {
    int op = 0, cl = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) op++;
        else cl++;
        if (cl > op) return false;
    }
    return cl == op;
}

void sol() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) sum += val[i].second;
		else sum += val[i].first;
	}
	ans = min(ans, sum);
}
 
void Try(int i) {
	if (i > n) {
		if (check()) sol();
	}
	else for (int j = 0; j <= 1; j++) {
		a[i] = j;
		Try(i + 1);
	}
}
 
int main() {
    fast
    cin >> n;
    for (int i = 1; i <= n; i++) 
    	cin >> val[i].first >> val[i].second;
    Try(1);
    cout << ans;
    return 0;
}