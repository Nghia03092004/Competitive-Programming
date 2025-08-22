#include <bits/stdc++.h>
using namespace std;
int n, a[6], d[6], ans = 0;
double x;

bool check() {
	double sum = 0;
	int j = 1;
	while (j <= n) {
		double tmp = a[j];
		int i = j;
		while ((d[j + 1] == 3 || d[j + 1] == 4) && (j <= n)) {
			j++;
			if (d[j] == 3) tmp *= a[j];
			else tmp /= a[j];
		}
		if (d[i] == 1) sum += tmp;
		else sum -= tmp;
		j++;
	}
	return abs(sum - x) <= 0.000000000001; // xet xap xi sum voi x xem thu co bang nhau khong
}
void Caculations(int i) {
	if (i > n) ans += check();
	else for (int j = 1; j <= 4; j++) {
			d[i] = j;
			Caculations(i + 1);
		}
}
void Try(int i) {
	if (i <= n)
		for (int j = 1; j <= 9;j++) {
			a[i] = j;
			Try(i + 1);
		}
	else Caculations(2); // bat dau gan phep tinh tu vi tri 2
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> x;
	d[1] = 1; // them + o dau cho de xu li
	Try(1);
	cout << ans;
	return 0;
} // small town boy in a big arcade