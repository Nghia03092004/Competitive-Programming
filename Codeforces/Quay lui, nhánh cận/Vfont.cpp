#include <bits/stdc++.h>
using namespace std;
const int N = 26;
int n;
long long ans = 0;
string a[N];
bool flag[256];
 
bool check(string s) {
    fill(flag, flag + 256, false);
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
        flag[s[i]] = true;
    }
    for (char i = 'a'; i <= 'z'; i++)
        if (!flag[i])
            return false;
    return true;
}
 
void Try(int i, string s) {
    if (check(s)) {
        ans += pow(2, n - i);
        return;
    }
 
    if (i == n)
        return;
 
    Try(i + 1, s + a[i]);
    Try(i + 1, s);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
    Try(0, "");
    cout << ans;
 
	return 0;
}