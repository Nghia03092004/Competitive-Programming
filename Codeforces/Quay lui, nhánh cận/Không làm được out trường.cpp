#include<bits/stdc++.h>
using namespace std;

int n;
bool vis['9' + 1];

void Try(int i, string s) {
	if (i == n) {
		cout << s << "\n";
		return;
	}
	for (char j = '1'; j <= '0' + n; j++) 
		if (!vis[j]) {
			vis[j] = true;
			Try(i + 1, s + j);
			vis[j] = false;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	Try(0, "");
	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int n;
// bool vis['9' + 1];

// void Try(int i, string s) {
// 	if (i == n + 1) {
// 		cout << s << "\n";
// 		return;
// 	}
// 	for (char j = '1'; j <= '0' + n; j++) 
// 		if (!vis[j]) {
// 			vis[j] = true;
// 			Try(i + 1, s + j);
// 			vis[j] = false;
// 		}
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);
// 	cin >> n;
// 	Try(1, "");
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int n, i, k, x, y;
// int a[10];

// void Swap(int *x, int *y) {
// 	int tmp = *x;
// 	*x = *y;
// 	*y = tmp;
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n;
// 	for (int j = 1; j <= n; j++) a[j] = j;
// 	do {
// 		for (int j = 1; j <= n; j++) cout << a[j];
// 		cout << "\n";
// 		i = n - 1;
// 		while (i > 0 && a[i] > a[i + 1]) i--;
// 		if (i > 0) {
// 			k = n;
// 			while (a[k] < a[i]) k--;
// 			Swap(&a[k], &a[i]);
// 			x = i + 1; y = n;
// 			while (x < y) {
// 				Swap(&a[x], &a[y]);
// 				x++; y--;
// 			}
// 		} 
// 	} while (i > 0);
// }  