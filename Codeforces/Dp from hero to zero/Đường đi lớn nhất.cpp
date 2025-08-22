#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e3 + 5;
int n , m;
int a[N][N] , f[N][N];

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> a[i][j];


    for(int i = 1 ; i <= n ; i++)
    	f[i][1] = a[i][1];

    for(int j = 2 ; j <= m ; j++) // chạy cột
        for(int i = 1 ; i <= n ; i++) // chay hàng
        {
    		f[i][j] = f[i][j - 1] + a[i][j];
    		if(i - 1 >= 1)
    			f[i][j] = max(f[i][j] , f[i - 1][j - 1] + a[i][j]);
    		if(i + 1 <= n)
    			f[i][j] = max(f[i][j] , f[i + 1][j - 1] + a[i][j]);
        }

    int ans = -1e18;
    for(int i = 1 ; i <= n ; i++)
    	ans = max(ans , f[i][m]);

    cout << ans;


}



#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
int m, n, a[N][N];
long long ans = -1e18, dp[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    for (int i = 0; i <= m; i++) 
        for (int j = 0; j <= m; j++) 
            dp[i][j] = -1e18;
    for (int i = 1; i <= m; i++) dp[i][1] = a[i][1];
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]}) + a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) 
        ans = max(ans, dp[i][n]);
    cout << ans;
    return 0;
}