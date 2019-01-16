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

template<class T> T gcd(T a,T b){return b==0?a:gcd(b,a%b);}

pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
	ll x,y;
	if (b==0) return mp(1,0);
	auto p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
    if (a*x + b*y == -gcd(a,b)) a = -a, b = -b;
	return mp(x,y);
}

ll inv(ll x, ll m){//O(log x)
	return extendedEuclid(x, -m).fst;
}

pair<pair<ll,ll>,pair<ll,ll> > diophantine(ll a,ll b, ll r) {
	//a*x+b*y=r where r is multiple of gcd(a,b);
	ll d=gcd(a,b);
	a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst+b*p.snd==r);
	return mp(p,mp(-b,a)); // solutions: (p.fst - b*k1, p.snd + a*k2)
}

#define mod(a,m) ((a)%(m) < 0 ? (a)%(m)+(m) : (a)%(m)) // evita overflow al no sumar si >= 0
typedef tuple<ll,ll,ll> ec;
pair<ll,ll> sol(ec c){ //requires inv, diophantine
    ll a=get<0>(c), x1=get<1>(c), m=get<2>(c), d=gcd(a,m);
    if (d==1) return mp(mod(x1*inv(a,m),m), m);
    else return x1%d ? mp(-1LL,-1LL) : sol({a/d,x1/d,m/d});
}
pair<ll,ll> crt(vector< ec > cond) { // returns: (sol, lcm)
	ll x1=0,m1=1,x2,m2;
	for(auto t:cond){
		tie(x2,m2)=sol(t);
		if((x1-x2)%gcd(m1,m2))return mp(-1,-1);
		if(m1==m2)continue;
		ll k=diophantine(m2,-m1,x1-x2).fst.snd,l=m1*(m2/gcd(m1,m2));
		x1=mod(m1*mod(k, l/m1)+x1,l);m1=l; // evita overflow con prop modulo
	}
	return sol(make_tuple(1,x1,m1));
} //cond[i]={ai,bi,mi} ai*xi=bi (mi); assumes lcm fits in ll

const int B = 10+5, Z = 100+5;
const ll INF = LLONG_MAX;
int f[B][Z], start[B], cycle[B], pos[B][Z], pre[B];
bool seen[Z];

int main() {
	fastio;
	
    int b, z; cin >> b >> z;
    forn(i, b) {
        cin >> start[i]; start[i]--;
        forn(j, z) { 
            cin >> f[i][j]; 
            f[i][j]--; 
        }
    }

    // precalc
    int mxpre = 0;
    forn(i, b) {
        fill(seen, seen+z, false);
        fill(pos[i], pos[i]+z, -1);

        cerr << "en b " << i << endl;

        int act = start[i], len = 0;
        while (!seen[act]) {
            seen[act] = true;
            pos[i][act] = len;
            cerr << "zoo " << act << " en pos " << len << endl;

            act = f[i][act];
            len++;
        }

        int cyclestart = act;
        act = start[i];
        while (act != cyclestart) { act = f[i][act]; pre[i]++; }
        cycle[i] = len - pre[i];
        mxpre = max(mxpre, pre[i]);

        cerr << "ciclo " << cycle[i] << " pre " << pre[i] << endl;
    }

    // solve
    ll ans = INF, zans;
    forn(j, z) {
        vector<ec> v;
        bool can = true;
        cerr << "zoo " << j << endl;
        int must = -1;
        forn(i, b) {
            if (pos[i][j] == -1) { can = false; break; }
            if (pos[i][j] < pre[i]) { must = pos[i][j]; break; }

            v.pb(1, pos[i][j]%cycle[i], cycle[i]);
            cerr << "x = " << pos[i][j]%cycle[i] << " mod " << cycle[i] << endl;
        }     

        if (!can) continue;

        if (must != -1) {
            forn(i, b) 
                can &= (pos[i][j] < pre[i] && pos[i][j] == must) 
                    || (pos[i][j] >= pre[i] && must >= pre[i] && pos[i][j]-pre[i] == (must-pre[i])%cycle[i]);
            
            cerr << "must " << must << " could? " << can << endl;
            if (!can) continue;
            if (must < ans) {
                ans = must;
                zans = j;
            }
            continue;
        }


        auto sol = crt(v);
        if (sol == mp(-1LL,-1LL)) continue;
        while (sol.fst < mxpre) sol.fst += sol.snd;
        cerr << "ans x = " << sol.fst << endl;

        if (sol.fst < ans) {
            ans = sol.fst;
            zans = j;
        }
    }

    if (ans == INF) cout << '*' << endl;
    else cout << zans+1 << ' ' << ans << endl;
	
	return 0;
}
