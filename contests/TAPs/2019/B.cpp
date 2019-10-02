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

int sq(int x) { return x * x; }

struct Point {
    int x, y;

    Point operator - (Point o) { return {x - o.x, y - o.y}; }
    int norm_sq() { return x*x + y*y; }
};

int dist_sq(Point p, Point q) { return (p - q).norm_sq(); }

struct Circle {
    Point o; int r;

    Circle() : o({0, 0}), r(0) {}
};

bool inter(Circle a, Circle b) {
    return dist_sq(a.o, b.o) <= sq(a.r + b.r);
}

bool in(Circle a, Circle b) {
    return dist_sq(a.o, b.o) < sq(a.r - b.r);
}

int main() {
	fastio;
	
    int n; cin >> n;
    vector<Circle> circles(n); for (Circle &c : circles) cin >> c.o.x >> c.o.y >> c.r;

    bool ans = true;
    forn(i, n) forsn(j, i + 1, n) {
        Circle a = circles[i], b = circles[j];
        if (inter(a, b) && !in(a, b)) ans = false;
    }

    cout << (ans ? "SI" : "NO") << endl;

	return 0;
}
