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

const double EPS=1e-9, INF = 1e18, PI = acos(-1);
struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(const pto &a)const{return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(const pto &a) const {return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
    bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
    bool operator!=(pto a){return !(*this==a);}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}
double dist_sq(pto a, pto b){return (b-a).norm_sq();}

double angle(pto a, pto o, pto b){
	pto oa=a-o, ob=b-o;
	return atan2(oa^ob, oa*ob);
}

double cotan(double angle) {
    return cos(angle) / sin(angle);
}

struct RadialOrder {//orden total de puntos alrededor de un punto r
    pto r;
    RadialOrder(pto r) : r(r) {}
    int cuad(const pto &a) const {
        if(a.x > 0 && a.y >= 0)return 0;
        if(a.x <= 0 && a.y > 0)return 1;
        if(a.x < 0 && a.y <= 0)return 2;
        if(a.x >= 0 && a.y < 0)return 3;
        return -1;
    }
    bool comp(const pto &p1, const pto &p2) const {
        int c1 = cuad(p1), c2 = cuad(p2);
        if (c1 == c2) return (p1 ^ p2) > 0;
        else return c1 < c2;
    }
    bool operator()(const pto &p1, const pto &p2) const {
        return comp(p1 - r, p2 - r);
    }
};

int main() {
	fastio;
	
    int t; cin >> t;
    while (t--) {
        int k; cin >> k; int n = 4*k+5;
        vector<pto> points(n); forn(i, n) cin >> points[i].x >> points[i].y; 

        double ans = INF;
        for (pto center : points) {
            vector<pto> orderedPoints = points;
            orderedPoints.erase(find(all(orderedPoints), center));
            sort(all(orderedPoints), RadialOrder(center));

            int m = n-1;
            vi indArms = {0, k+1, 2*k+2, 3*k+3};

            forn(_, m) {
                bool works = true;
                double act = 0;
                //cerr << "center " << center.x << ' ' << center.y << endl;
                forn(i, 4) {
                    pto a = orderedPoints[indArms[i]], 
                        b = orderedPoints[indArms[(i+1)%4]];
                    //cerr << a.x << ' ' << a.y << endl;

                    double ang = angle(a, center, b);
                    if (ang < 0) ang = 2*PI - ang;
                    if (ang >= PI + EPS) { works = false; break; }

                    act += abs(cotan(ang));
                }

                if (works) ans = min(ans, act);

                for (int &i : indArms) i = (i+1)%m;
            }
        }

        if (ans == INF) cout << "Impossible" << endl;
        else cout << fixed << setprecision(6) << ans << endl;
    }

	return 0;
}
