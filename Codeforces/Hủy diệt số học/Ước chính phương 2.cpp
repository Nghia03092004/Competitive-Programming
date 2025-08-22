#include<bits/stdc++.h>
 
using namespace std;
 
int l, r, ans = 0;
int IsSquare[1001];
 
bool Square_Check(int n)
{
    int i = 2;
    while(i * i <= n)
    {
        int cnt = 0;
        while(n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if(cnt >= 2) return true;
        i++;
    }
    return false;
}
 
 
int main()
{
   cin >> l >> r;
   for(int i = l; i <= r; i++)
        if(Square_Check(i)) IsSquare[i - l] = 1;
    for(int i = l; i <= r - 1; i++)
        for(int j = i + 1; j <= r; j++)
            if(__gcd(i, j) != 1 || IsSquare[i - l]|| IsSquare[j - l]) ans++;
 
    cout << ans;
}