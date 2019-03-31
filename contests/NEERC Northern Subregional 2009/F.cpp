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
        return x < o.x - EPS || (abs(x - o.x) <= EPS && y < o.y - EPS);
    }
    bool operator == (const pto &o) const {
        return abs(x - o.x) <= EPS && abs(y - o.y) <= EPS;
    }
    bool operator != (const pto &o) const { return !(*this == o); }
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator*(double a){return pto(x*a, y*a);}
    double operator*(pto p){return x*p.x + y*p.y;}
	double operator^(pto a){return x*a.y-y*a.x;}
	double norm(){return sqrt(x*x+y*y);}
};
using vp = vector<pto>;
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

pto u(double alfa) {
    return {cos(alfa), sin(alfa)};
}
pto v(double alfa) {
    return {cos(alfa+PI/2), sin(alfa+PI/2)};
}

vd extremesD(pto vec, pto a, pto b) {
    return {vec*a, vec*b};
}

vp extremesP(pto vec, pto a, pto b) {
    cerr << "proy " << a << " y " << b << " sobre " << vec << endl;
    cerr << "da " << vec*(vec*a) << " y " << vec*(vec*b) << endl;
    return {vec*(vec*a), vec*(vec*b)};
}

double difExtremes(pto vec, pto a, pto b) {
    vd e = extremesD(vec, a, b);
    return abs(e[0] - e[1]);
}

double difSides(pto vec1, pto vec2) {
    return abs(difExtremes(vec1, so[0], so[2]) - difExtremes(vec2, so[1], so[3]));
}

double difSides(double alfa) {
    return difSides(u(alfa), v(alfa));
}

void sortPoly(pto p[N]) {
    sort(p, p+N);
    cerr << "ref " << p[0] << endl;
    sort(p+1, p+N, [p](pto a, pto b) { return ((a-p[0])^(b-p[0])) > EPS; });
}

void buildExtremes(double alfa) {
    pto vec1 = u(alfa), vec2 = v(alfa);

    vp e0 = extremesP(vec1, so[0], so[2]), e1 = extremesP(vec2, so[1], so[3]);
    forn(i, 2) forn(j, 2) {
        se[i*2+j] = e0[i] + e1[j];
        cerr << "comb " << e0[i] << " con " << e1[j] << " da " << se[i*2+j] << endl;
    }
    sortPoly(se);
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
    sortPoly(so);
    forn(i, N) cerr << so[i] << endl;

    double lo = 0, hi = PI/2;

    forn(_, 200) {
        double a = lo+(hi-lo)/3, b = lo+2*(hi-lo)/3;

        if (difSides(a) < difSides(b)) hi = b;
        else lo = a;
    }

    double alfa = lo;
    cerr << "alfa " << alfa << " cost " << difSides(alfa) << endl;
    
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

    if (vertices) cerr << "v" << endl, buildExtremes(alfa + PI/4);
    else {
        bool sol = true;
        forn(i, N) if (cnt[i] != 1) sol = false;

        if (!sol) bye();
    }

    forn(i, N) cout << se[i].x << ' ' << se[i].y << endl;

	return 0;
}
