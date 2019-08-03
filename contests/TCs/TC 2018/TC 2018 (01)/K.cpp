#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const double EPS=1e-9;
const double INF = 1e18;

struct pto{
	double x, y;
    int ind;
	pto(double x=0, double y=0, int ind = -1):x(x),y(y), ind(ind){}
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
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>EPS;}
    bool in(pto q, pto r) {return abs((q-*this)^(r-*this)) <= EPS;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
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

const int MAXN = 1e5+10, MAXM = 2e4+10;
pto a[MAXN], b[MAXM];

int main() {
    fastio;

    int n, m;
    cin >> n; forn(i, n) {
        cin >> a[i].x >> a[i].y;
        a[i].ind = i;
    }
    cin >> m; forn(i, m) cin >> b[i].x >> b[i].y;

    vector<pto> v;
    pto start = a[0], nxt = a[1], pre = a[n-1];
    forsn(i, 1, n) v.pb(a[i]);
    bool can = true;
    forn(i, m) {
        if (b[i].left(start, nxt) || b[i].in(start, nxt) || !b[i].left(start, pre)) {
            can = false;
            //cerr << b[i].x << ' ' << b[i].y << endl;
            //cerr << b[i].left(start,nxt) << ' ' << b[i].in(start,nxt) << ' ' << !b[i].left(start,pre) << endl;
        }
        else
            v.pb(b[i]);
    }

    if (can) {
        //cerr << "can? " << can << endl;
        sort(all(v), [&](pto a, pto b) {
            return ((a-start)^(b-start)) < 0; // all good? paralelos
        });

        /*
        for (pto p : v)
            cerr << p.x << ' ' << p.y << endl;
        return 0;
        */

        int act = 0;
        for (pto p : v) {
            if (p.ind != -1) act = p.ind;
            else {
                //cerr << "chequeo " << p.x << ' ' << p.y << " vs segm ";
                //cerr << a[act].x << ' ' << a[act].y << ' ' << a[act+1].x << ' ' << a[act+1].y << endl;
                line lseg(a[act], a[act+1]), lpto(start, p);
                pto intersec = inter(lseg, lpto);
                if (dist(start, p) > dist(start, intersec) - EPS)        
                    can = false;
            }
            //cerr << "can? " << can << endl;
        }
    }

    cout << (can ? "YES" : "NO") << endl;

    return 0;
}
