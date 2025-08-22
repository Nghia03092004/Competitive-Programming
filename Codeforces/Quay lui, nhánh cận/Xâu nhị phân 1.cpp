#include<bits/stdc++.h>
using namespace std;

int n;

void Try(int i, string s) {
	if (i == n) {
		cout << s << "\n";
		return;
	}
	Try(i + 1, s + '0');
	Try(i + 1, s + '1');
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
 
// const int N = 20;
// int n, a[N];
 
// void printResult() {
// 	for (int i = 1; i <= n; i++) cout << a[i];
// 	cout << "\n";
// }
 
// void Try(int i) {
// 	for (int j = 0; j <= 1; j++) {
// 		a[i] = j;
// 		if (i == n) printResult();
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
// // back tracking

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 20;
// int n, i, a[N];

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	cin >> n;
// 	fill(a + 1, a + n + 1, 0);
// 	do {
// 		for (int j = 1; j <= n; j++) cout << a[j];
// 		cout << "\n";
// 		i = n;
// 		while (i > 0 && a[i] == 1) i--;
// 		if (i > 0) {
// 			a[i] = 1;
// 			fill(a + i + 1, a + n + 1, 0);
// 		}
// 	} while (i > 0);
// }
// //generation method