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

const double EPS=1e-9;
struct pto {
	ll x, y, z;
	pto(ll _x=0, ll _y=0,ll _z=0):x(_x),y(_y),z(_z){}
	pto operator+(pto a){return pto(x+a.x, y+a.y, z+a.z);}
	pto operator-(pto a){return pto(x-a.x, y-a.y,z-a.z);}
	//pto operator+(double a){return pto(x+a, y+a);}
	//pto operator*(double a){return pto(x*a, y*a);}
	//pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	ll operator*(pto a){return x*a.x+y*a.y+z*a.z;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	pto operator^(pto a){return pto(
            y*a.z-z*a.y,
            z*a.x-x*a.z,
            x*a.y-y*a.x
            );}
	//returns true if this is at the left side of line qr
	//bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	//bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
    //bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	//double norm(){return sqrt(x*x+y*y);}
	ll norm_sq(){return x*x+y*y+z*z;}
};
//double dist(pto a, pto b){return (b-a).norm();}
//double dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

bool colinear(vec u,vec v){
    return (u^v).norm_sq()==0;
}

bool ortonormal(vec u,vec v){
    return u*v == 0;
}


int main() {
	fastio;
	
    int n;
    cin >> n;
    vector<pto> points(n);
    for(pto& a:points)cin >> a.x >> a.y >> a.z;

    bool coplanar = true;
    
    int res=0;
    for(pto a:points){
        for(pto b:points){
            for(pto c:points){
                vec u = b-a, v = c-a;
                if(!colinear(u,v)){
                    coplanar=false;
                    int cant =0;
                    vec norm = u^v;
                    //cerr << norm.x << " " << norm.y << " " << norm.z << endl;
                    for(pto d:points){
                        vec w = d-a;
                        cant+= ortonormal(norm,w);
                    }
                    //D(cant);
                    res = max(cant,res);
                } 
            }
        }
    }
    if(coplanar)res = n;

    cout << res << endl;

	
	return 0;
}

