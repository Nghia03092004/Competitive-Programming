#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n";
int n, x;
char a[18];

void print() {
	for (int i = 1; i <= 2*n - 1; i++) cout << a[i] << " ";
	cout << endl;
}

bool check() {
	int sum = (int)(a[1] - 48);
	for (int i = 3; i <= 2*n - 1; i += 2) {
		if (a[i - 1] == '+') sum += (int)(a[i] - 48);
		else sum -= (int)(a[i] - 48);
	}
	return sum == x;
}

void Try(int i) {
	if (i % 2 == 1) {
		for (char j = '1'; j <= '5'; j++) {
			a[i] = j;
			if (i == 2*n - 1) {
				if (check()) print(); 
			} else Try(i + 1);
		} 
	} else for (int j = 0; j <= 1; j++) {
		if (j == 0) a[i] = '+';
		else a[i] = '-';
		Try(i + 1);
	}
}

int main() {
	fast
	cin >> n >> x;
	Try(1);
}