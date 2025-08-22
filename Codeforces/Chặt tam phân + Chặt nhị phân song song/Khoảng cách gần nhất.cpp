#include<bits/stdc++.h>

using namespace std;

#define double long double 

const int maxN = (int) 1e5 + 5;
int q;
double xa, xb, xc, xd, ya, yb, yc, yd;

double f(double x) {
    double p_x1 = xa + (xb - xa) * x;
    double p_y1 = ya + (yb - ya) * x;

    double p_x2 = xc + (xd - xc) * x;
    double p_y2 = yc + (yd - yc) * x;
    return sqrt((p_x1 - p_x2) * (p_x1 - p_x2) + (p_y1 - p_y2) * (p_y1 - p_y2));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

        double l = 0, r = 1;
        for (int i = 1; i <= 100; ++i) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if (f(m1) > f(m2)) 
                l = m1;
            else 
                r = m2;
        }

        cout << setprecision(6) << fixed << f(l) << '\n';
    }

    return 0;
}