#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,abm,mmx,popcnt,tune=native")
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
using type = int;
 
int mod;
 
struct Matrix {
    vector<vector<int>> data;
 
    int row() const { return data.size(); }
    int col() const { return data[0].size(); }
 
    auto & operator [] (int i) { return data[i]; }
    const auto & operator [] (int i) const { return data[i]; }
 
    Matrix() = default;
    Matrix(int r, int c): data(r, vector<type> (c)) { }
    Matrix(const vector<vector<type>> &d): data(d) {
        assert(d.size());
        int size = d[0].size();
        assert(size);
        for (auto x: d) assert(x.size() == size);
    }
 
    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x: d.data) {
            for (auto y: x) out << y << ' ';
            out << '\n';
        }
        return out;
    }
 
    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }
 
    Matrix operator * (const Matrix &b) {
        Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k) {
                   c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
        return c;
    }
 
     Matrix pow(long long exp) {
        assert(row() == col());
        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
     }
};
 
main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    char x, y; cin >> x >> y;
    int n, p; cin >> n >> p;
    mod = p;
    Matrix I(24, 24);
 
    I[0][3] = I[0][5] = 1;
    I[1][7] = I[1][9] = 1;
    I[2][1] = I[2][5] = 1;
    I[3][10] = I[3][19] = 1;
    I[4][1] = I[4][3] = 1;
    I[5][17] = I[5][15] = 1;
    I[6][0] = I[6][9] = 1;
    I[7][11] = I[7][13] = 1;
    I[8][0] = I[8][7] = 1;
    I[9][14] = I[9][20] = 1;
    I[10][6] = I[10][13] = 1;
    I[11][2] = I[11][19] = 1;
    I[12][6] = I[12][11] = 1;
    I[13][21] = I[13][23] = 1;
    I[14][4] = I[14][17] = 1;
    I[15][8] = I[15][20] = 1;
    I[16][4] = I[16][15] = 1;
    I[17][18] = I[17][22] = 1;
    I[18][2] = I[18][10] = 1;
    I[19][16] = I[19][22] = 1;
    I[20][12] = I[20][23] = 1;
    I[21][8] = I[21][14] = 1;
    I[22][12] = I[22][21] = 1;
    I[23][16] = I[23][18] = 1;
 
    I = I.pow(n - 1);
 
    Matrix A(24, 1);
    if (x == 'A') A[0][0] = A[2][0] = A[4][0] = 1;
    else if (x == 'B') A[1][0] = A[6][0] = A[8][0] = 1;
    else if (x == 'C') A[7][0] = A[10][0] = A[12][0] = 1;
    else if (x == 'D') A[3][0] = A[11][0] = A[18][0] = 1;
    else if (x == 'E') A[5][0] = A[14][0] = A[16][0] = 1;
    else if (x == 'F') A[9][0] = A[15][0] = A[21][0] = 1;
    else if (x == 'G') A[13][0] = A[20][0] = A[22][0] = 1;
    else A[19][0] = A[17][0] = A[23][0] = 1;
 
    I = I * A;
 
    int ans = 0;
 
    if (y == 'A') ans = (ans + I[1][0] + I[3][0] + I[5][0]) % mod;
    else if (y == 'B') ans = (ans + I[0][0] + I[7][0] + I[9][0]) % mod;
    else if (y == 'C') ans = (ans + I[6][0] + I[11][0] + I[13][0]) % mod;
    else if (y == 'D') ans = (ans + I[2][0] + I[10][0] + I[19][0]) % mod;
    else if (y == 'E') ans = (ans + I[4][0] + I[15][0] + I[17][0]) % mod;
    else if (y == 'F') ans = (ans + I[8][0] + I[14][0] + I[20][0]) % mod;
    else if (y == 'G') ans = (ans + I[12][0] + I[21][0] + I[23][0]) % mod;
    else ans = (ans + I[16][0] + I[18][0] + I[22][0]) % mod;
 
    cout << ans;
 
}