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

    vector<Interval> split() {
        if (start <= end + EPS) return { {start, end} };
        return { {start, PI}, {-PI, end} };
    }

    bool empty() {
        return start > end + EPS;
    }
};

Interval intersect(Interval a, Interval b) {
    return {max(a.start, b.start), min(a.end, b.end)};
}

int main() {
	fastio;
	
    int n; cin >> n;
    vector<Point> points(n); vi vals(n);
    forn(i, n) cin >> points[i].x >> points[i].y >> vals[i];

    vector<Interval> intersections = { {-PI, PI} };
    forn(i, n) forsn(j, i + 1, n) if (vals[i] != vals[j]) {
        Point p = points[i], q = points[j];
        if (vals[i] < vals[j]) swap(p, q);

        Vector pq = q - p;
        Vector start_vec = pq.rot90();
        Vector end_vec = start_vec.flip();
        vector<Interval> nintervals = Interval(start_vec.angle(), end_vec.angle()).split();

        vector<Interval> nintersections;
        for (Interval &pinterval : intersections) {
            for (Interval &ninterval : nintervals) {
                Interval rinterval = intersect(pinterval, ninterval);

                if (!rinterval.empty()) nintersections.pb(rinterval);
            }
        }
        intersections = nintersections;
    }

    cout << (intersections.empty() ? 'N' : 'Y') << endl;
	
	return 0;
}
