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
	ll x, y;
	pto(ll x=0, ll y=0):x(x),y(y){}
	pto operator+(const pto a)const{return pto(x+a.x, y+a.y);}
	pto operator-(const pto a)const{ return pto(x-a.x, y-a.y);}
	pto operator+(ll a){return pto(x+a, y+a);}
	pto operator*(const ll a)const {return pto(x*a, y*a);}
	pto operator/(ll a){return pto(x/a, y/a);}
	//dot product, producto interno:
	ll operator*(const pto a)const {return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	ll operator^(const pto a)const {return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x|| (x==a.x&& y<a.y);}
    bool operator==(const pto a)const {return x == a.x && y == a.y;}
	//double norm(){return sqrt(x*x+y*y);}
	ll norm_sq(){return x*x+y*y;}
};
//double dist(pto a, pto b){return (b-a).norm();}
ll dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

//double angle(pto a, pto o, pto b){
//	pto oa=a-o, ob=b-o;
//	return atan2(oa^ob, oa*ob);
//}

//rotate p by theta rads CCW w.r.t. origin (0,0)
//pto rotate(pto p, double theta){
//	return pto(p.x*cos(theta)-p.y*sin(theta),
//     p.x*sin(theta)+p.y*cos(theta));
//}


//orden total de puntos alrededor de un punto r
// hacer operadores ^ y - constantes
struct RadialOrder {
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
    bool operator()(const pto&p1, const pto&p2) const {
        return comp(p1 - r, p2 - r);
    }
};

bool acute(vec a,vec b){
    return (a^b) > 0 && (a*b) >0;
}

bool comp(vec a, vec b, vec c, vec d){
    return (a*b)*(a*b)*c.norm_sq()*d.norm_sq() > (c*d)*(c*d)*a.norm_sq()*b.norm_sq();
}

bool equals(vec a, vec b, vec c, vec d){
    return (a*b)*(a*b)*c.norm_sq()*d.norm_sq() == (c*d)*(c*d)*a.norm_sq()*b.norm_sq() &&
        a.norm_sq()*d.norm_sq()==b.norm_sq()*c.norm_sq();
}

vector<vector<pto>> pres;

void similars(int index, vec u, vec v, vector<pto> pts){
    RadialOrder ctro(pts[index]);
    pts.erase(pts.begin()+index);
    sort(all(pts),ctro);

    forn(p1,si(pts)){
        int p2 = (p1+1)%si(pts);
        while(p2!=p1 && acute(pts[p1]-ctro.r, pts[p2]-ctro.r)&& comp(pts[p1]-ctro.r, pts[p2]-ctro.r, u, v)){
            p2 = (p2+1)%si(pts);
        }
        if(equals(pts[p1]-ctro.r, pts[p2]-ctro.r, u, v)){
            vector<pto> sol = {ctro.r, pts[p1], pts[p2]};
            sort(all(sol));
            pres.pb(sol);
        }
    }


}

int main() {
	fastio;
	
    int n;
    cin >> n;

    vector<pto> points(n);
    for(pto& a:points)cin >>a.x >> a.y;

    vector<pto> triang = {points[0],points[1],points[2]};
    RadialOrder aux({0,0});
    ll res =0;
    forn(ind,si(points)){
        forn(i,3){
            vec u = triang[(i+1)%3]-triang[i],
                v = triang[(i+2)%3]-triang[i];
            if(aux(v,u))swap(u,v);
            similars(ind,u,v,points);
        }
    }

    sort(all(pres));
    int cant = unique(all(pres)) - pres.begin();
    cout << cant << endl;

	
	return 0;
}
