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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const double EPS=1e-9, PI = acos(-1);
struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
    double norm_sq() {return x*x+y*y;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>=-EPS;}
};
double dist(pto a, pto b){return (b-a).norm();}

double angle(pto a, pto o, pto b){
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);}

//rotate p by theta rads CCW w.r.t. origin (0,0)
pto rotate(pto p, double theta){
	return pto(p.x*cos(theta)-p.y*sin(theta),
     p.x*sin(theta)+p.y*cos(theta));
}

vector<pto> chull(vector<pto> P)
{
	int n = si(P), k = 0;
	if (n == 1) return P;
	vector<pto> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
    forn(i, n) {
		while (k >= 2 && P[i].left(H[k-2], H[k-1])) k--;
		H[k++] = P[i];
	}

	// Build upper hull
    int t = k+1;
    dforsn(i, 0, n-1) {
		while (k >= t && P[i].left(H[k-2], H[k-1])) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}

struct circle {
	pto o;
	double r;

    circle(pto o={0,0}, double r=0) : o(o), r(r) {}
};

vector<pto> tangents(circle c1, circle c2) {
    if (c1.r > c2.r) return tangents(c2, c1);

    vector<pto> t;

    double o1o2 = dist(c1.o, c2.o), po2 = c2.r-c1.r,
           alfa = asin(po2/o1o2), beta = PI/2 - alfa;

    pto start1 = c1.o - c2.o, start2 = c1.o - c2.o;
    start1 = start1/start1.norm(); start2 = start2/start2.norm();
    start1 = start1*c1.r; start2 = start2*c2.r;

    t.pb(c1.o + rotate(start1, -beta));
    t.pb(c1.o + rotate(start1, beta));
    t.pb(c2.o + rotate(start2, -beta));
    t.pb(c2.o + rotate(start2, beta));

    return t;
}

int getCircle(vector<circle> &cs, pto &p) {
    forn(i, si(cs))
        if ((dist(p, cs[i].o) - cs[i].r) < EPS)
            return i;
}

double arc(circle &c, pto &a, pto &b) {
    double ang = angle(a, c.o, b);
    if (ang < 0) ang = -ang;
    else ang = 2*PI- ang;
    return ang*c.r; 
}

int main() {
	fastio;

    cout << fixed << setprecision(10);

    int nc; cin >> nc;
    while (nc--) {
        int n; cin >> n;     

        vector<circle> cs(n);
        forn(i, n) cin >> cs[i].o.x >> cs[i].o.y >> cs[i].r;

        if (n == 1) {
            cout << 2*PI*cs[0].r << endl;
            continue;
        }

        vector<pto> ps;
        forn(i, n) forsn(j, i+1, n) 
            for (pto p : tangents(cs[i], cs[j]))            
                ps.pb(p);

        ps = chull(ps);

        // calc
        int m = si(ps); double len = 0;
        forn(i, m) {
            int j = (i+1)%m, ci = getCircle(cs, ps[i]), cj = getCircle(cs, ps[j]);

            if (ci == cj) 
                len += arc(cs[ci], ps[i], ps[j]);
            else  
                len += dist(ps[i], ps[j]);
        }
        cout << len << endl;
    }    
	
	return 0;
}
