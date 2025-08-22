#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
bool prime[N];

void sieve() {
	for (int i = 1; i <= N; i++) prime[i] = true;
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (prime[i])
			for (int j = i*i; j <= N; j += i) 
				prime[j] = false;
	}
}

int Check(int n) {
    int cnt=0,tmp;
    for (int i = 2; i <= sqrt(n); i++) {
        if (i*i>n) break;
        while (n%i==0) {
            cnt++;
            tmp=i;
            n/=i;
        }
        if (cnt>1) return -1;
    }
    if (cnt==1) return tmp;
    else return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	long long n;
	cin >> n;
	while (Check(n)==-1) {
        n--;
	}
	cout  << n;
}