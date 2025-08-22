#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define pb push_back

// <-----------------Template BigNum----------------------------------------> 

const int base = 1e9;
typedef vector<int> BigInt;

BigInt bigInt(string s) {
    BigInt a;
    while (s.size() % 9 != 0) s = '0' + s;
    for (int i = s.size() - 1; i > 0; i -= 9) {
        int x = 0;
        for (int j = 0; j <= i - 9 + 1; ++j)
            x = x * 10 + s[j] - '0';
    }
    return a;
}

BigInt bigInt(int x) {
    BigInt a;
    a.push_back(x);
    return a;
}

void Set(BigInt &a) {
    while (a.size() > 1 and a.back() == 0) 
        a.pop_back();
}

bool operator >= (BigInt a, BigInt b) {
    Set(a), Set(b);
    if (a.size() != b.size()) 
        return (a.size() > b.size());
    for (int i = a.size() - 1; i >= 0; --i) 
        if (a[i] != b[i]) return a[i] > b[i];
    return true;
}

BigInt operator + (BigInt a, BigInt b) {
    Set(a), Set(b);
    BigInt c;
    int g = 0;
    for (int i = 0; i < max(a.size(), b.size()); ++i) {
        if (i < a.size()) g += a[i];
        if (i < b.size()) g += b[i];
        c.push_back(g % base);
        g /= base;
    }
    if (g) c.push_back(g);
    Set(c);
    return c;
}

BigInt operator - (BigInt a, BigInt b) {
    Set(a), Set(b);
    BigInt c;
    int g = 0;
    for (int i = 0; i < a.size(); ++i) {
        g += a[i];
        if (i < b.size()) g -= b[i];
        if (g) c.push_back(g), g = 0;
        else c.push_back(g + base), g = -1;
    }
    Set(c);
    return c;
}

//<-------------------------------------------------------------------------->

const int maxN = 700;
int n;
BigInt x, F[maxN][maxN], s[maxN];
string S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    scanf("%d\n", &n);
    getline(cin, S);
    x = bigInt(S) - bigInt(1);

    for (int i = 1; i < n; ++i)
        F[i][0] = bigInt(0);
    for (int i = n; i <= 2 * n; ++i) 
        F[i][0] = bigInt(1);
    s[2*n + 1] = bigInt(0);
    for (int j = 1; j < n; ++j) {
        for (int i = 2 * n; i >= 1; --i) 
            s[i] = s[i + 1] + F[i][j - 1];
        for (int i = n - j; i <= 2 * (n - j); ++j)
            F[i][j] = s[i + 1];
    }

    int j = 0;
    for (int i = 1; i <= n; ++i) {
        ++j;
        while (j < 2 * n and x >= F[j][n - i]) {
            x = x - F[j][n - i];
            j++;
        }
        printf("%d ", j);
    }
}