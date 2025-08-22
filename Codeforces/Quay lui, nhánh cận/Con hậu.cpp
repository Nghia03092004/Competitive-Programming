#include<bits/stdc++.h>
using namespace std;

char arr[10][10];
int n, m, ans = 0, cnt = 0;
int a[10], b[10], c[10];

void Try(int i) {
	if (i > n) ans = max(ans, cnt);
	else for (int j = 0; j <= m; j++) {
		if (!j) Try(i + 1);
		if (!a[j] && !b[i - j + n] && !c[i + j] && arr[i][j] == '.') {
			cnt++;
			a[j] = true, b[i - j + n] = true, c[i + j] = true;
			Try(i + 1);
			cnt--;
			a[j] = false, b[i - j + n] = false, c[i + j] = false;
		}  
	}	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> arr[i][j]; 
	Try(1);
	cout << ans;
}