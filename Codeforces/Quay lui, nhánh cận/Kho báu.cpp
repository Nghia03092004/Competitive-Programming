#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int t, ans = 0, num;
int a[5][5], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[5][5];

void Try(int i, int x, int y) {
if (i == 9) ans = max(ans, num);
	else for (int j = 0; j < 4; j++) {
		int u = x + dx[j], v = y + dy[j];
		if (vis[u][v] == false && u >= 1 && u <= 3 && v >= 1 && v <= 3) {
			num = num * 10 + a[u][v];
			vis[u][v] = true;
			Try(i + 1, u, v);
			num /= 10;
			vis[u][v] = false;
		}		
	}
}


int main() {
	fast
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				vis[i][j] = false;
			}
		}
		ans = 0;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				num = a[i][j];
				vis[i][j] = true;
				Try(1, i, j);
				vis[i][j] = false;
			}
		}
		cout << ans << endl;
	}
}