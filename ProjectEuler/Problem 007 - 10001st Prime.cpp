#include<bits/stdc++.h>
using namespace std;
 
const int maxN = 1e6 + 5;
bool prime[maxN];
vector<int> ans;
 
void sieve() {
    for (int i = 1; i < maxN; i++) {
        prime[i] = true;
    }
    prime[1] = false;
    for (int i = 2; i  * i < maxN; i++) {
        if (prime[i])
            for (int j = i * i; j <= maxN; j += i) 
                prime[j] = false;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    sieve();
    ans.push_back(0);
    for (int i = 2; i < maxN; ++i) 
        if (prime[i]) ans.push_back(i);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}