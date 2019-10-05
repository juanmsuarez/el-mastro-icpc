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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Point operator -(Point o) const { return {x - o.x, y - o.y}; }
    ll operator ^(Point o) const { return x * o.y - y * o.x; }

    bool left(Point q, Point r) { return ((q - *this)^(r - *this)) > 0; }

    bool operator == (Point o) { return x == o.x && y == o.y; }
};

struct RadialOrder {
	Point r;
	RadialOrder(Point _r) : r(_r) {}
	int quad(const Point &a) const {
		if (a.x > 0 && a.y >= 0) return 0;
		if (a.x <= 0 && a.y > 0) return 1;
		if (a.x < 0 && a.y <= 0) return 2;
		if (a.x >= 0 && a.y < 0) return 3;
		return -1;
	}
	bool comp(const Point &p1, const Point &p2) const {
		int c1 = quad(p1), c2 = quad(p2);
		if (c1 == c2) return (p1 ^ p2) > 0;
        else return c1 < c2;
	}
    bool operator()(const Point &p1, const Point &p2) const {
        return comp(p1 - r, p2 - r);
    }
};

ll choose(int n, int k) {
    if (k == 1) return n;
    if (n == 0) return 0;
    return (ll) n * choose(n - 1, k - 1) / k;
}

int main() {
	fastio;
	
    int n; cin >> n;
    vector<Point> points(n); for (Point &p : points) cin >> p.x >> p.y;

    ll concave_quads = 0;
    for (Point inner_point : points) {
        ll outside_triangs = 0;

        auto other_points = points; other_points.erase(find(all(other_points), inner_point));
        sort(all(other_points), RadialOrder(inner_point));

        int m = n - 1;
        int j = 0;
        forn(i, m) {
            Point &start_point = other_points[i];

            while (j - i < m && !other_points[j % m].left(start_point, inner_point)) j++;
            outside_triangs += choose(j - i - 1, 2);
        }
        
        ll total_triangs = choose(n - 1, 3);
        concave_quads += total_triangs - outside_triangs;
    }

    ll total_quads = choose(n, 4);
    cout << total_quads - concave_quads << endl;
	
	return 0;
}
