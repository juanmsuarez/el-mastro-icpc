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

const double EPS=1e-9, INF = 1e9;
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
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}
double dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line() {}
	double a,b,c;//Ax+By=C
//pto MUST store float coordinates!
	line(double a, double b, double c):a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
};
bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
pto inter(line l1, line l2){//intersection
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);//parallels
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

vec perp(vec v){return vec(-v.y, v.x);}
line bisector(pto x, pto y){
	line l=line(x, y); pto m=(x+y)/2;
	return line(-l.b, l.a, -l.b*m.x+l.a*m.y);
}
struct Circle{
	pto o;
	double r;
    Circle (pto _o={0,0}, double _r=0) : o(_o), r(_r) {}
	pair<pto, pto> ptosTang(pto p){
		pto m=(p+o)/2;
		double d=dist(o, m);
		double a=r*r/(2*d);
		double h=sqrt(r*r-a*a);
		pto m2=o+(m-o)*a/d;
		vec per=perp(m-o)/d;
		return make_pair(m2-per*h, m2+per*h);
	}
};
//finds the center of the circle containing p1 and p2 with radius r
//as there may be two solutions swap p1, p2 to get the other
bool circle2PtsRad(pto p1, pto p2, double r, pto &c){
        double d2=(p1-p2).norm_sq(), det=r*r/d2-0.25;
        if(det<0) return false;
        c=(p1+p2)/2+perp(p2-p1)*sqrt(det);
        return true;
}
#define sqr(a) ((a)*(a))
#define feq(a,b) (fabs((a)-(b))<EPS)
pair<double, double> ecCuad(double a, double b, double c){//a*x*x+b*x+c=0
	double dx = sqrt(b*b-4.0*a*c);
	return make_pair((-b + dx)/(2.0*a),(-b - dx)/(2.0*a));
}
pair<pto, pto> interCL(Circle c, line l){
	bool sw=false;
	if((sw=feq(0,l.b))){
	swap(l.a, l.b);
	swap(c.o.x, c.o.y);
	}
	pair<double, double> rc = ecCuad(
	sqr(l.a)+sqr(l.b),
	2.0*l.a*l.b*c.o.y-2.0*(sqr(l.b)*c.o.x+l.c*l.a),
	sqr(l.b)*(sqr(c.o.x)+sqr(c.o.y)-sqr(c.r))+sqr(l.c)-2.0*l.c*l.b*c.o.y
	);
	pair<pto, pto> p( pto(rc.first, (l.c - l.a * rc.first) / l.b),
					  pto(rc.second, (l.c - l.a * rc.second) / l.b) );
	if(sw){
	swap(p.first.x, p.first.y);
	swap(p.second.x, p.second.y);
	}
	return p;
}
struct segm{
	pto s,f;
	segm(pto s, pto f):s(s), f(f) {}
	pto closest(pto p) {//use for dist to point
	   double l2 = dist_sq(s, f);
	   if(l2==0.) return s;
	   double t =((p-s)*(f-s))/l2;
	   if (t<0.) return s;//not write if is a line
	   else if(t>1.)return f;//not write if is a line
	   return s+((f-s)*t);
	}
    bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS;}
};

//NOTA: Si los segmentos son coolineales solo devuelve un punto de interseccion
pto inter(segm s1, segm s2){
    if(s1.inside(s2.s)) return s2.s; //Fix cuando son colineales
    if(s1.inside(s2.f)) return s2.f; //Fix cuando son colineales
	pto r=inter(line(s1.s, s1.f), line(s2.s, s2.f));
    if(s1.inside(r) && s2.inside(r)) return r;
	return pto(INF, INF);
}

Circle c; 
pto pqo; 
int x[2], y[2];

bool in(pto a) {
    //cerr << "dist " << dist(c.o, a) << " rad " << c.r << endl;
    return dist(c.o, a) <= c.r + EPS;
}

bool check(segm s) {
    return in(s.closest(c.o));
}

bool can(double r) {
    c.r = r;

    //cerr << r << endl;

    //cerr << "circulo rect " << pqo.x << ' ' << pqo.y << " y " << c.o.x << ' ' << c.o.y << endl;
    if (check(segm({x[0], y[0]}, {x[0], y[1]}))) return false;
    if (check(segm({x[1], y[0]}, {x[1], y[1]}))) return false;
    if (check(segm({x[0], y[0]}, {x[1], y[0]}))) return false;
    if (check(segm({x[0], y[1]}, {x[1], y[1]}))) return false;

    return true;    
}

int main() {
	fastio;
	
    cin >> c.o.x >> c.o.y >> x[0] >> y[0] >> x[1] >> y[1];
    sort(x, x+2); sort(y, y+2);

    pqo = {(x[1] - x[0])/2., (y[1] - y[0])/2.};


    double lo = 0, hi = INF;
    forn(_, 200) {
        double mid = (lo + hi) / 2;
        if (can(mid)) lo = mid;
        else hi = mid;
    }

    cout << fixed << setprecision(3) << lo << endl;
	
	return 0;
}
