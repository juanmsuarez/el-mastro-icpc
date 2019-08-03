#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforn(i,n) dforsn(i, 0, n)
#define forn(i,n) forsn(i, 0, n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef long long int ll;
typedef vector<int> vi;


const double EPS=1e-9, INF = 1e18;
struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator/(double a){return pto(x/a, y/a);}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
};
struct line{
	double a,b,c;//Ax+By=C
//pto MUST store float coordinates!
	line(double a=0, double b=0, double c=0):a(a),b(b),c(c){}
    bool in(pto p){return abs(a*p.x + b*p.y - c) < EPS; }
};
bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
pto inter(line l1, line l2){//intersection
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);//parallels
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}
// END REPO !!!

typedef vector<line> vl;

int n;

bool solve(int k, vl v) {
    if (v.empty() && k == 0) return true;
    if (k == 0) return false;

    // busco inters
    line boss = v[0];
    set<pto> inters;
    for (line l : v) if (!parallels(boss, l)) inters.insert(inter(boss, l));
    inters.insert(inter(boss, {1, 0, 0})); 
    inters.insert(inter(boss, {0, 1, 0}));

    // pruebo inters
    for (pto p : inters) {
        vl w;
        for (line l : v) if (!l.in(p)) w.pb(l);
        if (solve(k-1, w)) return true; 
    }
    
    return false;
}

int main() {
    fastio;


    int k; cin >> n >> k;
    vl v(n);
    forn(i, n) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].c *= -1;
    }
   
    cout << (solve(k, v) ? "YES" : "NO") << endl;

    return 0;
}
