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
    Point operator - (Point a) { return {x - a.x, y - a.y}; }
    int norm_sq() { return x * x + y * y; }
};

ll dist_sq(Point p, Point q) {
    return (p - q).norm_sq();
}

struct Circle {
    Point o; int r;
    Circle(Point _o = {0, 0}, int _r = 0) : o(_o), r(_r) {}
};

int sq(int x) { return x * x; }

bool inter(Circle c1, Circle c2) {
    return dist_sq(c1.o, c2.o) <= sq(c1.r + c2.r); 
}

int w, h;
bool border_inter0(Circle c) {
    return c.o.x - c.r <= 0 || c.o.y + c.r >= h;
}

bool border_inter1(Circle c) {
    return c.o.x + c.r >= w || c.o.y - c.r <= 0;
}

const int N = 1e3;

vector<Circle> circles;

vi adj[N];
bool seen[N];

bool block(int u) {
    if (border_inter1(circles[u])) return true;
    seen[u] = true;

    for (int v : adj[u]) if (!seen[v] && block(v)) return true;

    return false;
}

int main() {
	fastio;

    int n; cin >> w >> h >> n;
    circles.resize(n); 
    for (auto &[o, r] : circles) cin >> o.x >> o.y >> r;

    forn(i, n) forsn(j, i + 1, n) if (inter(circles[i], circles[j]))
        adj[i].pb(j), adj[j].pb(i);

    bool blocked = false;
    forn(i, n) if (border_inter0(circles[i])) 
        if (!seen[i] && block(i)) { 
            blocked = true; 
            break; 
        }

    cout << (blocked ? 'N' : 'S') << endl;
	
	return 0;
}

