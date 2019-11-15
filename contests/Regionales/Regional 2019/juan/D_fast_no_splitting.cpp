#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
#define is_empty _is_empty
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const int INF = 1e9;

const double PI = acos(-1);

const double EPS = 1e-9;

struct Point {
    int x, y;   

    Point(int _x = 0, int _y = 0): x(_x), y(_y) {}

    Point operator-(Point &o) { return {x - o.x, y - o.y}; }
    int operator*(Point &o) { return x * o.x + y * o.y; }
    int operator^(Point &o) { return x * o.y - y * o.x; }

    double angle() { return atan2(y, x); }

    Point rot90() { return Point(y, -x); }
    Point flip() { return Point(-x, -y); }
};
using Vector = Point;

struct Interval {
    double start, end;

    Interval(double _start, double _end): start(_start), end(_end) {}

    bool empty() {
        if (start <= end + EPS) return false;
        return start - PI < end - EPS;
    }

    bool in(double x) {
        if (start <= end + EPS) return x >= start - EPS && x <= end + EPS;
        return x >= start - EPS || x <= end + EPS;
    }
};
const Interval NULL_INT = {INF + 1, INF};

Interval intersect(Interval a, Interval b) {
    if (a.in(b.start) && a.in(b.end)) return b;
    if (b.in(a.start) && b.in(a.end)) return a;
    
    if (a.in(b.start)) return {b.start, a.end};
    if (b.in(a.start)) return {a.start, b.end};
    return NULL_INT;
}

struct IntervalUnion {
    Interval a, b;

    IntervalUnion(Interval _a = NULL_INT, Interval _b = NULL_INT): a(_a), b(_b) {}

    bool empty() { return a.empty() && b.empty(); }
};

int main() {
	fastio;
	
    int n; cin >> n;
    vector<Point> points(n); vi vals(n);
    forn(i, n) cin >> points[i].x >> points[i].y >> vals[i];

    bool split = false;
    IntervalUnion intersections = {{-PI, PI}};
    forn(i, n) forsn(j, i + 1, n) if (vals[i] != vals[j]) {
        Point p = points[i], q = points[j];
        if (vals[i] < vals[j]) swap(p, q);

        Vector pq = q - p;
        Vector start_vec = pq.rot90();
        Vector end_vec = start_vec.flip();
        Interval ninterval = {start_vec.angle(), end_vec.angle()};

        if (!split && abs(intersections.a.end - ninterval.start) <= EPS 
                && abs(intersections.a.start - ninterval.end) <= EPS) {
            split = true;
            intersections = {{ninterval.start, ninterval.start}, {ninterval.end, ninterval.end}};
        }
        else {
            if (!intersections.a.empty()) 
                intersections.a = intersect(intersections.a, ninterval);
            if (!intersections.b.empty())
                intersections.b = intersect(intersections.b, ninterval);
        }
    }

    cout << (intersections.empty() ? 'N' : 'Y') << endl;
	
	return 0;
}
