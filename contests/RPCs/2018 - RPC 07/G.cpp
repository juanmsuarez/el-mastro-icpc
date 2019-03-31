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

const ll INF = 1e18;
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
	bool operator<(const pto &a) const{return x<a.x || (x==a.x && y<a.y);}
bool operator==(pto a){return x==a.x && y==a.y;}
	ll norm_sq(){return x*x+y*y;}
};
ll dist_sq(pto a, pto b){return (b-a).norm_sq();}

int sgn(ll x) {
    return (x > 0) - (x < 0);
}
struct line{
	line() {}
	ll a,b,c;//Ax+By=C
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	int side(pto p){return sgn(a * p.x + b * p.y - c);}
    bool inside(pto p) {
        return a*p.x + b*p.y == c;
    }
};

struct segm{
	pto s,f;
	segm(pto s = {0, 0}, pto f = {0, 0}):s(s), f(f) {}
    bool inside(pto p){return dist_sq(s, p)+dist_sq(p, f)-dist_sq(s, f) == 0;}
    bool operator < (const segm &o) const {
        pto mn1 = min(s, f), mx1 = max(s, f),
            mn2 = min(o.s, o.f), mx2 = max(o.s, o.f);
        return mn1 < mn2 || (mn1 == mn2) && (mx1 < mx2);
    }
};

bool inter(segm s1, segm s2) {
    line l1(s1.s, s1.f), l2(s2.s, s2.f);
    return l1.side(s2.s) != l1.side(s2.f) && l2.side(s1.s) != l2.side(s1.f);
}

bool colinear(segm s1, segm s2){
    line l (s1.s, s1.f);
    return l.inside(s2.s) && l.inside(s2.f);
}

const int MAXN = 1e3+10;
segm s[MAXN];
vi adj[MAXN];
int ncmp = 0, comp[MAXN], nodos[MAXN], arcos[MAXN];

void calcComp(int u) {
    comp[u] = ncmp;

    for (int v : adj[u])
        if (comp[v] == -1)
            calcComp(v);
}

int main() {
    fastio;

    int n;
    cin >> n;
    forn(i, n) 
        cin >> s[i].s.x >> s[i].s.y >> s[i].f.x >> s[i].f.y;

    sort(s, s+n);

    vector<segm> temp;
    forn(i, n) {
        segm s1 = s[i];

        bool in = false;
        for (segm &s2 : temp) {
            if (colinear(s1, s2) && inter(s1, s2)) {
                in = true;
                pto mn = min(s1.s, min(s1.f, min(s2.s, s2.f))),
                    mx = max(s1.s, max(s1.f, max(s2.s, s2.f)));
                s2 = segm(mn, mx);
            }
        }

        if (!in) temp.pb(s1);
    }
    
    n = si(temp);
    forn(i, n) s[i] = temp[i];
    //forn(i, n) cerr << s[i].s.x << ' ' << s[i].s.y << ' ' << s[i].f.x << ' ' << s[i].f.y << endl;

    forn(i, n) 
        forn(j, n)
            if (i != j && inter(s[i], s[j]))
                adj[i].pb(j);

    fill(comp, comp+n, -1);
    forn(u, n) 
        if (comp[u] == -1) {
            calcComp(u);
            ncmp++;
        }

    forn(i, n) {
        int inters = 0;

        forn(j, n) {
            if (i == j) continue;

            bool ptosInter = inter(s[i], s[j]);
            inters += ptosInter;
            if (i < j)
                nodos[comp[i]] += ptosInter;
        }

        if (inters > 0)
            arcos[comp[i]] += inters-1;
    }

    int ans = 0;
    forn(cmp, ncmp)
        if (nodos[cmp] > 0) {
            //cerr << nodos[cmp] << ' ' << arcos[cmp] << endl;
            ans += 2 - nodos[cmp] + arcos[cmp] - 1;
        }

    cout << ans << endl;

    return 0;
}
