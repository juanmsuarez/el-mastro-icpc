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

const int INF =1000;
const double EPS=1e-9;
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
ostream& operator<<(ostream& os,pto& p){
    return os << fixed << setprecision(9) <<  p.x << " " << p.y;
}
double dist(pto a, pto b){return (b-a).norm();}
double dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

double angle(pto a, pto o, pto b){
    pto oa=a-o, ob=b-o;
    return atan2(oa^ob, oa*ob);}

    //rotate p by theta rads CCW w.r.t. origin (0,0)
    pto rotate(pto p, double theta){
        return pto(p.x*cos(theta)-p.y*sin(theta),
                p.x*sin(theta)+p.y*cos(theta));
    }

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

line bisector(pto x, pto y){
	line l=line(x, y); pto m=(x+y)/2;
	return line(-l.b, l.a, -l.b*m.x+l.a*m.y);
}
struct Circle{
	pto o;
	double r;
	Circle(pto x, pto y, pto z){
		o=inter(bisector(x, y), bisector(y, z));
		r=dist(o, x);
	}
};

pto reflect(pto A,pto B){
    return B*2.0-A;
}

bool convex(pto A,pto B,pto C,pto D){
    //cerr << A << " " << B << " " << C << " " << D << endl;
    vector<pto> quad = {A,B,C,D};
    forn(i,4){
        pto a=quad[(i+3)%4],b=quad[i],c=quad[(i+1)%4];
        double crossp = (c-b)^(a-b);
        //D(crossp);
        if(crossp<-EPS || abs(crossp)<EPS)return false;
    }
    //cerr << "convex" << endl;
    return true;
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
    //cerr << "k" << endl; 
	return pto(INF, INF);
}

bool simple(pto A,pto B,pto C,pto D){
    vector<pto> quad = {A,B,C,D};
    forn(i,2){
        segm a(quad[i],quad[(i+1)%4]); 
        int j=(i+2)%4;
        segm b(quad[j],quad[(j+1)%4]);
        if(a.inside(inter(a,b)))return false;
    }
    return true;
}

int main() {
    fastio;

    int t;
    cin >> t;


    while(t--){
        vector<pto> midpoints(3);
        cin >> midpoints[0].x >> midpoints[0].y >> midpoints[1].x >> midpoints[1].y >> midpoints[2].x >> midpoints[2].y;
        sort(all(midpoints));
        bool exists=false;
        do{
            pto K = midpoints[0], L = midpoints[1], M = midpoints[2];
            pto M2 = reflect(M,L);
            pto B = Circle(K,M2,L).o;
            pto A = reflect(B,K);
            pto C = reflect(B,L);
            pto D = reflect(C,M);
            if(convex(A,B,C,D)&& simple(A,B,C,D)){
                cout << "YES" << endl;
                cout << A << " " << B << " " << C << " " << D <<endl;
                exists=true;
                break;
            }
        }while(next_permutation(all(midpoints)));
        if(!exists)cout << "NO" << endl;
    }


    return 0;
}

