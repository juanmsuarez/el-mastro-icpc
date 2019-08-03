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

const ll EPS=1e-9;
struct pto{
	ll x, y;
	pto(ll x=0, ll y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(ll a){return pto(x+a, y+a);}
	pto operator*(ll a){return pto(x*a, y*a);}
	pto operator/(ll a){return pto(x/a, y/a);}
	//dot product, producto interno:
	ll operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	ll operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	ll norm(){return sqrt(x*x+y*y);}
	ll norm_sq(){return x*x+y*y;}
};
ll dist(pto a, pto b){return (b-a).norm();}
ll dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

ll area(vector<pto> &p){//O(sz(p))
	ll area=0;
	forn(i, si(p)) area+=p[i]^p[(i+1)%si(p)];
	//if points are in clockwise order then area is negative
	return abs(area);
}
//Area ellipse = M_PI*a*b where a and b are the semi axis lengths
//Area triangle = sqrt(s*(s-a)(s-b)(s-c)) where s=(a+b+c)/2

template<class T> T gcd(T a,T b){return b==0?a:gcd(b,a%b);}

int main() {
	fastio;
	
    int n; cin >> n;
    vector<pto> v;
    forn(i,n){
        int x,y; cin >> x >> y;
        v.pb(pto(x,y));
    }
    
    ll a = area(v), b = 0;
    forn(i,n){
        pto x = v[i]-v[(i+1)%n];
        b += abs(gcd(x.x,x.y));
    }
	ll res = (a-b+2)/2;
    cout << res << endl;
	return 0;
}
