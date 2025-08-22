#include<bits/stdc++.h>
using namespace std;

int n;

void Try(int i, int odd, int even, string s) {
	if (i == n) {
		if (odd == even) cout << s << "\n";
		return;
	}
	Try(i + 1, odd, even, s +'0');
	if (i % 2 == 0) Try(i + 1, odd + 1, even, s + '1');
	else Try(i + 1, odd, even + 1, s + '1');
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	Try(0, 0, 0, "");
	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 20;
// int n, a[N], sumE = 0, sumO = 0;

// void printResult() {
// 	if (sumO == sumE) {
// 		for (int i = 1; i <= n; i++) cout << a[i];
// 		cout << "\n";
// 	}
// }

// void Try(int i) {
// 	for (int j = 0; j <= 1; j++) {
// 		a[i] = j;
// 		if (i % 2) sumO += a[i]; else sumE += a[i];
// 		if (i == n) printResult();
// 		else Try(i + 1);
// 		if (i % 2) sumO -= a[i]; else sumE -= a[i];
// 	} 
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n;
// 	Try(1);
// }

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 20;
// int n, a[N];

// void printResult() {
// 	for (int i = 1; i <= n; i++) cout << a[i];
// 	cout << "\n";
// }

// void Try(int i) {
// 	for (int j = 0; j <= 1; j++) {
// 		a[i] = j;
// 		if (i == n) {
// 			int sumO = 0, sumE = 0;
// 			for (int i = 1; i <= n; i += 2) {
// 				sumO += a[i];
// 				sumE += a[i + 1];
// 			}
// 			if (sumO == sumE) printResult();
// 		}
// 		else Try(i + 1);
// 	}
// }

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n;
// 	Try(1);
// }