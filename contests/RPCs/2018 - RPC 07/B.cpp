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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const double EPS=1e-6, INF = 1e18;
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
};
bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
pto inter(line l1, line l2){//intersection
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);//parallels
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

struct Circle {
	pto o;
	double r;
    Circle(pto o = {0, 0}, double r = 0) : o(o), r(r) {}
};

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
pair<pto, pto> interCC(Circle c1, Circle c2){
	line l;
	l.a = c1.o.x-c2.o.x;
	l.b = c1.o.y-c2.o.y;
	l.c = (sqr(c2.r)-sqr(c1.r)+sqr(c1.o.x)-sqr(c2.o.x)+sqr(c1.o.y)
	-sqr(c2.o.y))/2.0;
	return interCL(c1, l);
}

const int MAXN = 30;
typedef pair<double,int> pdi;
vector<pdi> G[MAXN*MAXN];
//To add an edge use
int N;
#define add(a, b, w) G[a].pb(make_pair(w, b))
double dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<pdi, vector<pdi>, greater<pdi> > Q;
	vector<double> dist(N, INF); vector<int> dad(N, -1);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(si(Q)){
		pdi p = Q.top(); Q.pop();
		if(p.second == t) break;
        for (pdi e : G[p.second])
			if(dist[p.second]+e.first < dist[e.second]){
				dist[e.second] = dist[p.second] + e.first;
				dad[e.second] = p.second;
				Q.push(mp(dist[e.second], e.second));	}
	}
	return dist[t];
}

bool in(pto p, Circle c) {
    return dist(c.o, p) < c.r + EPS;
}

int n;
Circle c[MAXN];
vector<pto> inters;

bool alcanzable(pto a, pto b) {
    line l(a, b);

    int circleInd = -1;

    pto p = a;
    double dst = INF, oldDst;
    do {
        oldDst = dst;

        pto nextP = p;
        forn(i, n) {
            if (!in(p, c[i])) continue;

            if (in(b, c[i])) {
                dst = 0;
                circleInd = i;
            }
            else {
                pair<pto,pto> ps = interCL(c[i], l); 

                if (!isnan(ps.first.x) && dist(ps.first, b) < dst - EPS) {
                    dst = dist(ps.first, b);
                    nextP = ps.first;
                    circleInd = i;
                }
                if (!isnan(ps.second.x) && dist(ps.second, b) < dst - EPS) {
                    dst = dist(ps.second, b);
                    nextP = ps.second;
                    circleInd = i;
                }
            }
        }
        
        p = nextP;
    }
    while (dst < oldDst);

    //cerr << b.x << ' ' << b.y << " en " << 
      //  c[circleInd].o.x << ' ' << c[circleInd].o.y << ' ' << c[circleInd].r << endl;
    return circleInd != -1 && in(b, c[circleInd]);
}

int main() {
    fastio;

    pto s, e;
    cin >> s.x >> s.y >> e.x >> e.y;
    cin >> n;
    forn(i, n) cin >> c[i].o.x >> c[i].o.y >> c[i].r;

    forn(i, n) forsn(j, i+1, n) {
        double r1 = c[i].r, r2 = c[j].r, d = dist(c[i].o, c[j].o);
        if (r1 + r2 < d - EPS || max(r1, r2) > d + min(r1, r2) + EPS)
            continue;

        pair<pto, pto> p = interCC(c[i], c[j]);

        /*
        cerr << "inter entre " << c[i].o.x << ' ' << c[i].o.y << ' ' << r1
             << " y " << c[j].o.x << ' ' << c[j].o.y << ' ' << r2 << " es "
             << p.first.x << ' ' << p.first.y << " y "
             << p.second.x << ' ' << p.second.y << endl;
             */

        inters.pb(p.first);
        inters.pb(p.second);
    }

    inters.pb(s);
    inters.pb(e);
    sort(all(inters));
    inters.erase(unique(all(inters)), inters.end());

    N = si(inters);
    int indS, indE;
    forn(i, N) {
        if (inters[i] == s) indS = i;
        if (inters[i] == e) indE = i;
    }

    forn(i, N) forsn(j, i+1, N) {
        double d = alcanzable(inters[i], inters[j]) ? dist(inters[i], inters[j]) : INF;
        /*
        cerr << inters[i].x << ' ' << inters[i].y << " a " << 
                inters[j].x << ' ' << inters[j].y << " dist: " << d << endl;
                */
        add(i, j, d);
        add(j, i, d);
    }

    double d = dijkstra(indS, indE);
    if (d == INF) cout << "impossible" << endl;
    else cout << fixed << setprecision(6) << d << endl;

    return 0;
}
