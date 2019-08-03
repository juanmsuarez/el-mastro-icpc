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
	ll x, y;
    Point(ll _x=0, ll _y=0) : x(_x), y(_y) {}
	Point operator + (Point a) { return {x+a.x, y+a.y}; }
	Point operator - (Point a) { return {x-a.x, y-a.y}; }
	ll operator * (Point a) { return x*a.x+y*a.y; }
	ll operator ^ (Point a) { return x*a.y-y*a.x; }
	ll norm_sq(){return x*x + y*y;}
};
ll dist_sq(Point a, Point b){ return (b-a).norm_sq(); }
using Poly = vector<Point>;

struct Circle {
	Point o;
	ll r_sq;
    Circle(Point _o, ll _r_sq) : o(_o), r_sq(_r_sq) {}
    bool in(Point p) { return dist_sq(o, p) < r_sq; }
};


ll sq(ll a) { return a*a; }
struct Segment {
    Point s, f;
	Segment(Point s, Point f) : s(s), f(f) {}
    Segment operator + (Point d) { return {s + d, f + d}; } 
    bool closer(Point p, ll mx) {
        ll len = dist_sq(s, f);
        ll proj = (f - s) * (p - s);
        if (proj < 0 || proj > len) return false;

        ll dist = (f - s) ^ (p - s); // div len
        return sq(dist) <= mx * len;
    }
};

bool intersection(Circle c, Segment s) {
    if (c.in(s.s) && c.in(s.f)) return false;
    else if (c.in(s.s) || c.in(s.f)) return true;
    else return s.closer(c.o, c.r_sq);
}

bool collision(Point p, Point q, int n, int m, Poly &a, Poly &b) {
    Circle c(p, dist_sq(p, q));
    forn(i, n) {
        Segment s(a[i], a[(i+1)%n]);
        forn(j, m) {
            Point delta = q - b[j];
            Segment sd = s + delta;
            if (intersection(c, sd)) return true;
        } 
    }
    return false;
}

int main() {
	fastio;
	
    Point p; cin >> p.x >> p.y;
    int n; cin >> n;
    Poly a(n); for (auto &p : a) cin >> p.x >> p.y;
    Point q; cin >> q.x >> q.y;
    int m; cin >> m;
    Poly b(m); for (auto &p : b) cin >> p.x >> p.y;
        
    bool ans = collision(p, q, n, m, a, b) || collision(q, p, m, n, b, a);
    cout << (ans ? "YES" : "NO") << endl;
	
	return 0;
}
