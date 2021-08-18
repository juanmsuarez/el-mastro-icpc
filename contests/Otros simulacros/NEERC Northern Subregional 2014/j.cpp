#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

const double EPS = 1e-5;
struct Point {
	ll x, y;
	Point(ll _x=0, ll _y=0) : x(_x),y(_y) {}
	Point operator+(Point a) { return Point(x + a.x, y + a.y); }
	Point operator-(Point a) { return Point(x - a.x, y - a.y); }
	Point operator+(ll a) { return Point(x + a, y + a); }
	Point operator*(ll a) { return Point(x*a, y*a); }
	Point operator/(ll a) { return Point(x/a, y/a); }
	ll norm2() { return x*x + y*y; }
    // Dot product:
	ll operator*(Point a){ return x*a.x + y*a.y; }
	// Magnitude of the cross product (if a is less than 180 CW from b, a^b > 0):
	ll operator^(Point a) { return x*a.y - y*a.x; }
};
typedef Point vec;
ll dist2(Point a, Point b) { return (b-a).norm2(); }

int main() {
    fastio;
    freopen("joy.in","r",stdin);
    freopen("joy.out","w",stdout);
    
    Point s,f;
    cin >> s.x >> s.y >> f.x >> f.y;
    int n,k,vMax;
    cin >> n >> k >> vMax;
    vector<Point> positions(k);
    Point prevPos=s;
    int prevT=0; Point prevW(0,0);
    forn(i,n){
        int t;
        Point w;
        cin >> t>> w.x >> w.y;
        for(int j = prevT;j<t;j++){
            positions[j]=prevPos+prevW;
            prevPos=positions[j];
        }
        prevT=t,prevW=w;
    }
    forsn(j,prevT,k){
            positions[j]=prevPos+prevW;
            prevPos=positions[j];
    }
    forn(i,k){cerr << positions[i].x << " " << positions[i].y << endl;}
    ll rad = vMax*k;
    if(dist2(positions.back(),f) > rad*rad)cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        vec flight = f-positions.back();
        D(sqrt(double(flight.x*flight.x)+double(flight.y*flight.y)));
        cerr << flight.x << " " << flight.y << endl;
        forn(i,k){
            double x = positions[i].x + double((flight * (i+1)).x)/(double)k;
            double y = positions[i].y + double((flight * (i+1)).y)/(double)k;
            cout << fixed << setprecision(6) << x << " " << y << endl;
        }
    }


    
    return 0;
}

