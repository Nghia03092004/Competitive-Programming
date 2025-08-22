#include<bits/stdc++.h>
using namespace std;

int n;
bool vis['9' + 1];

void Try(int i, string s) {
	if (i == n) {
		cout << s << "\n";
		return;
	}
	for (char j = '0'; j <= '0' + n; j++) 
		if (!vis[j]) {
			vis[j] = true;
			Try(i + 1, s + j);
			vis[j] = false;
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (char j = '1'; j <= '0' + n; j++) {
		vis[j] = true;
		string s = "";
		s.push_back(j);
		Try(1, s);
		vis[j] = false;
	}
}


// #include<bits/stdc++.h>
// using namespace std;
 
// int n, sum = 0;
// bool flag[10];
 
// void Try(int i) {
// 	for (int j = 0; j <= n; j++) {
// 		if (i == 1 && j == 0) continue;
// 		if (!flag[j]) {
// 			sum = sum * 10 + j;
// 			flag[j] = true;
// 			if (i == n) cout << sum << "\n";
// 			else Try(i + 1);
// 			flag[j] = false;
// 			sum /= 10;
// 		}
// 	}
// }
 
// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n;
// 	Try(1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int n;
// bool vis['9'+1];
// void backTrack(string m, int k) {
//     if (k == n+1) {
//         cout << m << "\n";
//         return;
//     }
 
//     for (char i = '0'; i <= '0'+n; i++)
//         if (!vis[i]) {
//             vis[i] = 1;
//             backTrack(m + i, k+1);
//             vis[i] = 0;
//         }
// }
 
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0); cout.tie(0);
// 	cin >> n;
// 	for (char i = '1'; i <= '0' + n; i++) {
//         vis[i] = 1;
//         string temp = ""; temp.push_back(i);
//         backTrack(temp, 2);
//         vis[i] = 0;
// 	}
 
// 	return 0;
// }