#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 
using namespace std;
 
#define int long long
#define pow abcd
#define ii pair<int, int>
#define iiii pair<ii, ii>
#define fi first
#define se second
#define el '\n';
#define all(x) begin(x), end(x)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;
 
const int mod = 1e9 + 7;
const ld eps = 1e-28;

struct Segment {
    typedef Segment S;
    pair<ld, ld> x, y;
    explicit Segment(pair<ld, ld> ox, pair<ld, ld> oy) {
        if (ox.fi > oy.fi) swap (ox, oy);
        x = ox;
        y = oy;
    }

    ld evaluate(ld x_value) const {
        if (x.fi == y.fi) return x.se;
        ld slope = (x.se - y.se) / (x.fi - y.fi);
        return x.se + (x_value - x.fi) * slope;
    }

    ld find_common_point(S s) const {
        ld l = max(x.fi, s.x.fi);
        ld r = min(y.fi, s.y.fi);
        return l + (r - l) / 2.0;
    }

    bool operator == (S s) const {
        ld x_value = find_common_point(s);
        return abs(evaluate(x_value) - s.evaluate(x_value)) < eps;
    }

    bool operator < (S s) const {
        ld x_value = find_common_point(s);
        return (not ((*this) == s) and evaluate(x_value) < s.evaluate(x_value));
    }

    friend ostream& operator << (ostream& os, S s) {
        return os << "Segment((" << s.x.fi << "," << s.x.se << "),(" << s.y.fi << "," << s.y.se << "))";
    }
};


struct Fraction {
    typedef Fraction F;
    int x, y;
    explicit Fraction (int xx, int yy = 1) {
        assert(yy != 0);
        if (yy < 0) xx = -xx, yy = -yy;
        int d = __gcd(abs(xx), abs(yy));
        xx /= d; yy /= d;
        x = xx, y = yy;
    } 

    Fraction operator + (Fraction o) const {
        return Fraction(x*o.y + o.x*y, y * o.y);
    }

    Fraction operator - (Fraction o) const {
        return (*this) + Fraction(-o.x, o.y);
    }

    Fraction operator * (Fraction o) const {
        return Fraction(x*o.x, y*o.y);
    }

    Fraction operator / (Fraction o) const {
        return Fraction(x*o.y, y*o.x);
    }

    bool operator < (Fraction o) const {
        return x*o.y < o.x*y;
    }

    bool operator == (Fraction o) const {
        return x*o.y == o.x*y;
    }

    bool operator <= (Fraction o) const {
        return (*this) == o or (*this) < o;
    }

    friend ostream& operator << (ostream& os, F f) {
        return os << f.x << "/" << f.y;
    }
};


struct SegmentInt {
    typedef SegmentInt S;
    ii x, y;
    explicit SegmentInt(ii ox, ii oy) {
        if (tie(ox.fi, ox.se) > tie(oy.fi, oy.se)) swap(ox, oy);
        x = ox;
        y = oy;
    }

    Fraction evaluate(int x_value) const {
        if (x.fi == y.fi) return Fraction(x.se, 1);
        Fraction slope = Fraction(x.se - y.se, x.fi - y.fi);
        return Fraction(x.se)  + (Fraction(x_value) - Fraction(x.fi)) * slope;
    }

    ii find_common_point(S s) const {
        int l = max(x.fi, s.x.fi);
        int r = min(y.fi, s.y.fi);
        return {l, r};
    }

    bool operator == (S s) const {
        ii common = find_common_point(s);
        Fraction ta = evaluate(common.fi);
        Fraction tb = evaluate(common.se);
        Fraction sa = s.evaluate(common.fi);
        Fraction sb = s.evaluate(common.se);
        return (ta == sa) and (tb == sb);
    }

    bool operator < (S s) const {
        ii common = find_common_point(s);
        return (not ((*this) == s) and (evaluate(common.fi) <= s.evaluate(common.fi) and evaluate(common.se) <= s.evaluate(common.se))); 
    }

    friend ostream& operator << (ostream& os, S s) {
        return os << "Segment((" << s.x.fi << "," << s.x.se << "),(" << s.y.fi << "," << s.y.se << "))";
    }
};


template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int maxN = 2e5;
int n, m;
ii poly[maxN], points[maxN];
set<ii> in_poly;

pair<ld, ld> new_poly[maxN], new_points[maxN];
int result[maxN];

vector<ld> all_points;
vector<Segment> add_segment[maxN], rem_segment[maxN];
vector<pair<pair<ld, ld>, int>> query_points[maxN];
Tree<Segment> t;

vector<int> all_int_points;
vector<SegmentInt> add_segment_int[maxN], rem_segment_int[maxN], vertical_segment[maxN];
vector<pair<ii, int>> query_points_int[maxN];
Tree<Segment> t2;

map<int, vector<int>> M;

int get_all_points_index(ld x) {
    return distance(begin(all_points), lower_bound(all(all_points), x));
}

int get_all_int_points_index(int x) {
    return distance(begin(all_int_points), lower_bound(all(all_int_points), x));
}

pair<ld, ld> rotate(ii p) {
    return {p.fi * cos(1) - p.se * sin(1), p.fi * sin(1) + p.se * cos(1)};
}

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> 
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    bool operator < (P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator == (P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator + (P p) const { return P(x + p.x, y + p.y); }
    P operator - (P p) const { return P(x - p.x, y - p.y); }
    P operator * (T d) const { return P(x * d, y * d); }
    P operator / (T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross (P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return actan2(y, x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    P rotate(double a) const { return P(x*cos(a) - y*sin(a), x*sin(a) - y*cos(a)); }
    friend ostream& operator << (ostream* os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};


template <class P> bool onSegment(P s, P e, P p) {
    return P.cross(s, e) == 0 and (s - p).dot(e - p) <= 0;
}

template <class P> 
bool inPolygon(vector<P> &p, P a, bool strict = true) {
    int cnt = 0, n = (int)size(p);
    for (int i = 0; i < n; ++i) {
        P q = p[(i + 1) % n];
        if (onSegment(p[i], q, a)) return !strict;
        // if (segDist(p[i], q, a) <= eps) return not strict;
        cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
    }
    return cnt;
}

typedef Point<int> P;
vector<P> int_poly;

main() {
    ios::sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        poly[i] = {x, y}; in_poly.insert(poly[i]);
        all_int_points.push_back(x);
    }

    memset(result, -1, sizeof(result));
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
        if (in_poly.count(points[i])) result[i] = 1;
        all_int_points.push_back(x);
    }

    sort(all(all_int_points));
    all_int_points.erase(unique(all(all_int_points)), end(all_int_points));

    for (int i = 0; i < n; ++i) {
        SegmentInt seg = SegmentInt(poly[i], poly[(i + 1) % n]);
        if (seg.x.fi != seg.y.fi) {
            int id = get_all_int_points_index(seg.x.fi);
            add_segment_int[id].push_back(seg);
            id = get_all_int_points_index(seg.y.fi);
            rem_segment_int[id].push_back(seg);
        }  else {
            int id = get_all_int_points_index(seg.x.fi);
            vertical_segment[id].push_back(seg);
        }      
    }

    for (int i = 0; i < m; ++i) {
        if (result[i] == -1) {
            int id = get_all_int_points_index(points[i].fi);
            query_points_int[id].push_back({points[i], i});
        }
    }

    for (int i = 0; i < (int)all_int_points.size(); ++i) {
        for (auto seg: rem_segment_int[i]) {
            t2.erase(seg);
        }

        for (auto p: query_points_int[i]) {
            SegmentInt tmp = SegmentInt(p.fi, p.fi);
            int x = t2.order_of_key(tmp);
            auto it = t2.find_by_order(x);
            if (it != end(t2) and (*it) == tmp) {
                result[p.se] = 1;
                continue;
            }
        }

        for (auto seg: add_segment_int[i]) {
            t2.insert(seg);
        }
    }

    for (int i = 0; i < (int)all_int_points.size(); ++i) {
        M.clear();
        for (auto p: query_points_int[i])
            M[p.fi.se].push_back(p.se);
        for (auto p: vertical_segment[i])
            for (auto it = M.lower_bound(p.x.se); it != M.end() and (*it).fi <= p.y.se; ++it) 
                for (auto j: (*it).se) 
                    result[j] = 1;
    }

    for (int i = 0; i < n; ++i) {
        new_poly[i] = rotate(poly[i]);
        all_points.push_back(new_poly[i].fi);
    }

    for (int i = 0; i < m; ++i) {
        new_points[i] = rotate(points[i]);
        all_points.push_back(new_points[i].fi);
    }

    sort(all(all_points));
    all_points.erase(unique(all(all_points)), end(all_points));

    for (int i = 0; i < n; ++i) {
        Segment seg = Segment(new_poly[i], new_poly[(i + 1) % n]);
        int id = get_all_points_index(seg.x.fi);
        add_segment[id].push_back(seg);
        id = get_all_points_index(seg.y.fi);
        rem_segment[id].push_back(seg);
    }

    for (int i = 0; i < m; ++i) {
        if (result[i] == -1) {
            int id = get_all_int_points_index(new_points[i].fi);
            query_points[id].push_back({new_points[i], i});
        } 
    }

    int_poly.clear();
    for (int i = 0; i < n; ++i) 
        int_poly.push_back(P(points[i].fi, points[i].se));

    for (int i = 0; i < (int)all_points.size(); ++i) {
        for (auto seg: rem_segment[i]) 
            t.erase(seg); 

        for (auto p: query_points[i]) {
            Segment tmp = Segment(p.fi, p.fi);
            int x = t.order_of_key(tmp);
            auto it = t.find_by_order(x);
            if (it != end(t) and (*it) == tmp) {
                assert(false);
                continue;
            }
            result[p.se] = (x % 2 == 1);
        }

        for (auto seg: add_segment[i]) 
            t.insert(seg);
    }

    for (int i = 0; i < m; ++i) 
        if (result[i]) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    cerr << "Time elapsed: " << TIME << " s.\n";
}