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
typedef long long int tint;

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
    bool on(pto q, pto r){return (abs((q-*this)^(r-*this)))<EPS;}
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

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
// !!! left must return >= 0 to delete collinear points !!!
void chull(vector<pto> P, vector<pto> &l, vector<pto> &u)
{
	int n = P.size(), k = 0;
	vector<pto> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
    forn(i, n) {
		while (k >= 2 && P[i].left(H[k-2], H[k-1])) k--;
		H[k++] = P[i];
	}

    int mid = k;

	// Build upper hull
    int t = k+1;
    dforsn(i, 0, n-1) {
		while (k >= t && P[i].left(H[k-2], H[k-1])) k--;
		H[k++] = P[i];
	}

    forn(i, mid) {
        if (i+1 < mid && H[i].x == H[i+1].x) continue;
        u.pb(H[i]);
    }
    forsn(i, mid-1, k) {
        if (i+1 < k && H[i].x == H[i+1].x) continue;
        l.pb(H[i]);
    }
    reverse(all(l));
}

int main() {
    fastio;


    int n, m;
    cin >> n;
    vector<pto> a(n);
    forn(i, n) cin >> a[i].x >> a[i].y;
    cin >> m;
    vector<pto> b(m);
    forn(i, m)  cin >> b[i].x >> b[i].y;

    vector<pto> l, u;
    chull(a, l, u);

    /*
    cerr << 'l' << endl;
    forn(i, si(l)) cerr << l[i].x << ' ' << l[i].y << endl;
    cerr << 'u' << endl;
    forn(i, si(u)) cerr << u[i].x << ' ' << u[i].y << endl;
    */

    sort(all(b));

    int indl = 0, indu = 0, ans = 0;

    forn(i, m) {
        pto p = b[i];

        if (p.x < l[0].x) continue;

        while (indl+1 < si(l) && l[indl+1].x < p.x) indl++;
        while (indu+1 < si(u) && u[indu+1].x < p.x) indu++;

        if (indl+1 < si(l) && indu+1 < si(u) && !p.left(u[indu], u[indu+1]) && (p.left(l[indl], l[indl+1]) || p.on(l[indl], l[indl+1])))
            ans++;
    }

    cout << ans << endl;

    return 0;
}
