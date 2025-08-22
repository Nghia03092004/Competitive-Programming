#include<bits/stdc++.h>

using namespace std;

int makePalindrome(int x) {
    int ret = x * 1000;
    ret += x / 100;
    ret += ((x / 10) % 10) * 10;
    ret += (x % 10) * 100;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool found = false;
        for (int i = n / 1000; i >= 100 and !found; --i) {
            int palindrome = makePalindrome(i);
            if (palindrome >= n) continue;
            for (int factor = 100; factor * factor <= palindrome; ++factor) {
                if (palindrome % factor == 0) {
                    int other_factor = palindrome / factor;
                    if (other_factor <= 99 || other_factor >= 1000) continue;
                    cout << palindrome << '\n';
                    found = true;
                    break;
                }
            }
        }
    }
}