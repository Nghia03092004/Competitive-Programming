#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define pb push_back
using namespace std;
const int N = 7;
char a[N][N];
int n, m, ans = 0;
bool vis[N][N], col[N], row[N];
vector <ii> sto;
 
void Try(int cnt) {
    ans = max(ans, cnt);
    for (auto x : sto)
        if (!vis[x.fi][x.se] && !col[x.fi] && !row[x.se]) {
            vis[x.fi][x.se] = col[x.fi] = row[x.se] = true;
            Try(cnt + 1);
            vis[x.fi][x.se] = col[x.fi] = row[x.se] = false;
        }
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.') sto.pb({i, j});
		}
	}
	Try(0);
	cout << ans;
	return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
 
// char a[7][7];
// int n, m, cnt = 0, ans = 0;
// bool flag[7];
 
// void Try(int i) {
// 	if (i > n) ans = max(ans, cnt);
// 	else for (int j = 0; j <= m; j++) {
// 		if (!j) Try(i + 1);
// 		else if (!flag[j] && a[i][j] == '.') {
// 			flag[j] = true;
// 			cnt++;
// 			Try(i + 1);
// 			cnt--;
// 			flag[j] = false;
// 		}
// 	}
// }
 
// int main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= m; j++) {
// 			cin >> a[i][j];
// 		}
// 	}
// 	Try(1);
// 	cout << ans;
// }