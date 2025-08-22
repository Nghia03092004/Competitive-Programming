#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll M;
	cin >> M;
	ll x = M/3, y = M/15;
	cout << x*(2*3 + (x - 1)*3)/2 - y*(2*15 + (y - 1)*15)/2;
}