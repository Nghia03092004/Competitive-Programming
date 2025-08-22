#include<bits/stdc++.h>
using namespace std;

int n, k;

void Try(int i, int cnt, string s) {
	if (i == n) {
		cout << s << "\n";
		return;
	}
	Try(i + 1, cnt, s + '0');
	if (cnt < k) 
		Try(i + 1, ++cnt, s + '1');
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	Try(1, 1, "1");
	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 20;
// int n, k, a[N], cnt = 0;

// void printResult() {
// 	for (int i = 1; i <= n; i++) cout << a[i];
// 	cout << "\n";
// }

// void Try(int i) {
// 	for (int j = 0; j <= 1; j++) {
// 		if (i == 1 && j == 0) continue;
// 		if (j == 1) cnt++;
// 		if (cnt <= k) {
// 			a[i] = j;
// 			if (i == n) printResult();
// 			else Try(i + 1);
// 		}
// 		if (j == 1) cnt--;
// 	}
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n >> k;
// 	Try(1);
// }