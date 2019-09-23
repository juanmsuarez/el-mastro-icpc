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

    Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    Point operator - (Point o) { return Point(x - o.x, y - o.y); }
    double norm() { return sqrt(x * x + y * y); }
};

double dist(Point p, Point q) {
    return (p - q).norm();
}

using Poly = vector<Point>;

const int N = 4e3, INF = 1e9;

int n, target;
Poly poly;

int next(int x) { return (x + 1) % n; }
int prev(int x) { return (x - 1 + n) % n; }

double memo[N][N][2];
double dp(int left, int right, bool last_left) {
    int last = last_left ? left : right;
    if (next(left) == right) return last == target ? 0 : INF;

    double &res = memo[left][right][last_left];
    if (res != -1) return res;

    int next_left = next(left); 
    double res_move_left = dp(next_left, right, true) 
        + dist(poly[last], poly[next_left]);

    int prev_right = prev(right); 
    double res_move_right = dp(left, prev_right, false) 
        + dist(poly[last], poly[prev_right]);

    return res = min(res_move_left, res_move_right);
}

int main() {
	fastio;

    fill(memo[0][0], memo[N][0], -1);
    
    int start; cin >> n >> start >> target; start--, target--;
    poly.resize(n); for (Point &p : poly) cin >> p.x >> p.y;

    double ans = dp(start, start, true);
    cout << fixed << setprecision(6) << ans << endl;
	
	return 0;
}
