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


struct pto{
	ll x, y,z;
	pto(ll x=0, ll y=0,ll z=0):x(x),y(y),z(z){}
	pto operator+(pto a){return pto(x+a.x, y+a.y,z+a.z);}
	pto operator-(pto a){return pto(x-a.x, y-a.y,z-a.z);}
	pto operator+(ll a){return pto(x+a, y+a,z+a);}
	pto operator*(ll a){return pto(x*a, y*a,z*a);}
	pto operator/(ll a){return pto(x/a, y/a,z*a);}
	//dot product, producto interno:
	ll operator*(pto a){return x*a.x+y*a.y+z*a.z;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	pto operator^(pto a){return pto(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);}
	//returns true if this is at the left side of line qr
//	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
//	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
//bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
//	double norm(){return sqrt(x*x+y*y);}
//	double norm_sq(){return x*x+y*y;}
};
const double eps = 1e-7;

ll gcd(ll a,ll b){if(b == 0)return a;return gcd(b,a%b);}

//point prod(point p1, point p2){
//    ll x = p1.y*p2.z - p1.z*p2.y;
//    ll y = p1.x*p2.z - p1.z*p2.x;
//    ll z = p1.x*p2.y - p1.y*p2.x;
//    return point(x,y,z);
//}

int main() {
    fastio;

    int n; cin >> n;
    vector<point> l;
    forn(i,n){
        ll x,y,z; cin >> x >> y >> z;
        l.pb(x,y,z);
    }
    bool ok = 1;
    if(n > 3){
        point p1(l[0].x-l[1].x, l[0].y-l[1].y, l[0].z-l[1].z);
        bool line = 1;
        point p2;
        forsn(i,2,n){
            p2 = point(l[0].x-l[i].x, l[0].y-l[i].y, l[0].z-l[i].z);
            point p = prod(p1,p2);
            if(p.x != 0 || p.y != 0 || p.z != 0){
                line = 0;
                break;
            }
        }
        if(!line){
            point normal = prod(p1,p2);
            ll x = l[0].x*normal.x + l[0].y*normal.y + l[0].z*normal.z;
            forsn(i,2,n){
                if(x != l[i].x*normal.x + l[i].y*normal.y + l[i].z*normal.z) ok = 0;
                if(!ok) break;
            }
        }
    }
    cout << (ok ? "TAK\n" : "NIE\n");
    return 0;
}
