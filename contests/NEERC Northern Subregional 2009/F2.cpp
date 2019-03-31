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
using vd = vector<double>;
using ll = long long;

const int N = 4, INF = 1e9;
const double EPS = 1e-9, PI = acos(-1);

struct pto {
    double x, y;
    pto(double _x=0, double _y=0) : x(_x), y(_y) {}
    bool operator < (const pto &o) const {
        return atan2(y, x) < atan2(o.y, o.x);
    }
    bool operator == (const pto &o) const {
        return abs(x - o.x) <= EPS && abs(y - o.y) <= EPS;
    }
    bool operator != (const pto &o) const { return !(*this == o); }
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator*(double a){return pto(x*a, y*a);}
    double operator*(pto p){return x*p.x + y*p.y;}
	double norm(){return sqrt(x*x+y*y);}
};
double dist(pto a, pto b){return (b-a).norm();}
ostream& operator << (ostream &o, const pto &p) {
    o << '(' << p.x << ", " << p.y << ')';
    return o; 
}
bool inSegment(pto p, pto a, pto b) {
    cerr << "check " << p << " entre " << a << " y " << b;
    cerr << " cuenta da " << abs(dist(a, p)+dist(p, b)-dist(a, b)) << endl;
    return abs(dist(a, p)+dist(p, b)-dist(a, b)) <= EPS;       
}

pto so[N], se[N];

vd extremes(pto vec) {
    double mn = INF, mx = -INF;
    forn(i, N) {
        double p = so[i] * vec;
        mn = min(mn, p);
        mx = max(mx, p);
    }
    return {mn, mx};
}

double difExtremes(pto vec) {
    vd e = extremes(vec);
    return e[1] - e[0];
}

pto u(double alfa) {
    return {cos(alfa), sin(alfa)};
}
pto v(double alfa) {
    return {cos(alfa+PI/2), sin(alfa+PI/2)};
}

double difSides(double alfa) {
    return abs(difExtremes(u(alfa)) - difExtremes(v(alfa)));
}

void buildExtremes(double alfa) {
    vd eX = extremes(u(alfa)), eY = extremes(v(alfa));
    forn(i, 2) forn(j, 2) se[i*2+j] = u(alfa)*eX[i] + v(alfa)*eY[j];
    sort(se, se+N);
}

void bye() {
    forn(i, N) cout << 0 << ' ' << 0 << endl;
    exit(0);
}

int main() {
	fastio;

    //freopen("four.in", "r", stdin);
    //freopen("four.out", "w", stdout);

    cout << fixed << setprecision(7);

    forn(i, N) cin >> so[i].x >> so[i].y;
    sort(so, so+N);
	
    double lo = 0, hi = PI/2;

    forn(_, 200) {
        double a = lo+(hi-lo)/3, b = lo+2*(hi-lo)/3;

        if (difSides(a) < difSides(b)) hi = b;
        else lo = a;
    }

    double alfa = lo;
    cerr << "alfa " << alfa << endl;
    
    buildExtremes(alfa);

    int cnt[N] = {};
    forn(i, N) {
        bool used = false;
        forn(j, N) 
            if (inSegment(so[i], se[j], se[(j+1)%N])) 
                cnt[j]++, used = true;
        if (!used) bye();
    }

    forn(i, N) cerr << cnt[i] << ' ';
    cerr << endl;

    bool vertices = true;
    forn(i, N) if (cnt[i] != 2) vertices = false;

    if (vertices) cerr << "v" << endl, buildExtremes(alfa + PI/4); // TODO: o - PI/4?
    else {
        bool sol = true;
        forn(i, N) if (cnt[i] != 1) sol = false;

        if (!sol) bye();
    }

    forn(i, N) cout << se[i].x << ' ' << se[i].y << endl;

	return 0;
}
