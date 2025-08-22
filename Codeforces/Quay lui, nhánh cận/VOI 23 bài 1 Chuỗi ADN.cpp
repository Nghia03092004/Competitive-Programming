#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
string s;
int ans = 1e9;
bool flag[5];

bool checktest53() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '?') return true;
	} 
	return false;
}

void sol() {
	int tmp = 0;
	for (int l = 0; l < s.size(); l++) {
		for (int r = 0; r < s.size(); r++) {
			fill(flag + 1, flag + 4 + 1, false);
			for (int i = l; i <= r; i++) {
				if (s[i] == 'A') flag[1] = true;
				if (s[i] == 'T') flag[2] = true;
				if (s[i] == 'G') flag[3] = true;
				if (s[i] == 'X') flag[4] = true;
			}
			int cnt = 0;
			for (int i = 1; i <= 4; i++) 
				if (flag[i]) ++cnt;
			if (cnt >= 2) ++tmp;
		}
	}
	ans = min(ans, tmp);
}

void Try(int i) {
	if (i == s.size()) {
		sol(); return;
	} 
	if (s[i] == '?') {
		s[i] = 'A'; Try(i + 1);
		s[i] = 'T'; Try(i + 1);
		s[i] = 'G'; Try(i + 1);
		s[i] = 'X'; Try(i + 1);
		s[i] = '?';	
	} else Try(i + 1);
}

int main() {
	fast
	cin >> s;
	if (checktest53()) {
		Try(0); cout << ans;
	} else cout << 0;
	return 0;
}