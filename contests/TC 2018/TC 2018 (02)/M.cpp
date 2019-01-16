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

struct Line{ll m,h;};
ll inter(Line a, Line b){
    ll x=b.h-a.h, y=a.m-b.m;
    return x/y+(x%y?!((x>0)^(y>0)):0);//==ceil(x/y)
}
struct CHT {
	vector<Line> c;
	bool mx;
	int pos;
	CHT(bool mx=0):mx(mx),pos(0){}//mx=1 si las query devuelven el max
	inline Line acc(int i){return c[c[0].m>c.back().m? i : si(c)-1-i];}
	inline bool irre(Line x, Line y, Line z){
		return c[0].m>z.m? inter(y, z) <= inter(x, y)
                         : inter(y, z) >= inter(x, y);
	}
	void add(ll m, ll h) {//O(1), los m tienen que entrar ordenados
        if(mx) m*=-1, h*=-1;
		Line l=(Line){m, h};
        if(si(c) && m==c.back().m) { l.h=min(h, c.back().h), c.pop_back(); if(pos) pos--; }
        while(si(c)>=2 && irre(c[si(c)-2], c[si(c)-1], l)) { c.pop_back(); if(pos) pos--; }
        c.pb(l);
	}
	inline bool fbin(ll x, int m) {return inter(acc(m), acc(m+1))>x;}
	ll eval(ll x){
		int n = si(c);
		//query con x no ordenados O(lgn)
		int a=-1, b=n-1;
		while(b-a>1) { int m = (a+b)/2;
			if(fbin(x, m)) b=m;
			else a=m;
		}
		return (acc(b).m*x+acc(b).h)*(mx?-1:1);
        //query O(1)
		while(pos>0 && fbin(x, pos-1)) pos--;
		while(pos<n-1 && !fbin(x, pos)) pos++;
		return (acc(pos).m*x+acc(pos).h)*(mx?-1:1);
	}
} ch;

const int MAXN = 1e5+10;
int a[MAXN], b[MAXN];
ll sol[MAXN];

int main() {
    fastio;

    int n;
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    dforsn(i, 0, n) {
        if (i < n-1) {
            sol[i] = max(sol[i], ch.eval(b[i]));
            //cerr << ch.eval(b[i]) << endl;
        }
        ch.add(a[i], sol[i]);
        //cerr << "agrego " << a[i] << ' ' << sol[i] << endl;
        //cerr << sol[i] << endl;
    }

    cout << sol[0] << endl;

    return 0;
}
