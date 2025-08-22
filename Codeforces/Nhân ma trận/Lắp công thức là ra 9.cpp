#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
using type = int;
 
const int mod = 1e9 + 7;
 
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
                    c[i][j] += 1ll * a[i][k] % mod * (b[k][j] % mod) % mod;
                    c[i][j] %= mod;
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
 
 
    int sum = 0;
    int n, k; cin >> n >> k;
    int a[n], c[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) cin  >> c[i];
    int p, q, r; cin >> p >> q >> r;
 
    Matrix I(n + 4, n + 4);
    for (int i = 0; i < n; ++i) {
        I[0][i] = c[i + 1];
        I[n + 3][i] = c[i + 1];
    }
    I[0][n] = p, I[0][n + 1] = q, I[0][n + 2] = r;
    I[n + 3][n] = p, I[n + 3][n + 1] = q, I[n + 3][n + 2] = r, I[n + 3][n + 3] = 1;
 
    for (int i = 1; i < n; ++i) I[i][i - 1] = 1;
    I[n][n] = 1;
    I[n + 1][n] = I[n + 1][n + 1] = 1;
    I[n + 2][n] = I[n + 2][n + 2] = 1, I[n + 2][n + 1] = 2;    
    I = I.pow(k - n + 1);
 
    Matrix A(n + 4, 1);
    for (int i = 0; i < n; ++i) A[i][0] = a[n - 1 - i];
 
    A[n][0] = 1, A[n + 1][0] = n, A[n + 2][0] = n * n, A[n + 3][0] = sum;
    A = I * A;
 
    cout << A[n + 3][0];
}