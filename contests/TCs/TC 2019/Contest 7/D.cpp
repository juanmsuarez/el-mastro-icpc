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
using vii = vector<pii>;
using vll = vector<ll>;

// MODNTT-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
const int MAXN = 131072;
const ll MODNTT = 2305843009255636993;
const int RT = 5;
typedef unsigned long long ull;
ull mulmod(ull a, ull b, ull m){ // 0 <= a, b < m
   long double x; ull c; ll r;
   x = a; c = x * b / m;
   r = (ll)(a * b - c * m) % (ll)m;
   return r < 0 ? r + m : r;
}
struct MInt {
    ll m;
    MInt(ll _m=0) : m(_m) {}
    MInt operator * (const MInt &o) { return mulmod(m,o.m,MODNTT); }
    MInt operator + (const MInt &o) { return m + o.m >= MODNTT ? m + o.m - MODNTT : m + o.m; }
    MInt operator - (const MInt &o) { return m - o.m < 0 ? m - o.m + MODNTT : m - o.m; }
};
MInt pot(MInt b, ll e){ // O(log e)
	if(!e) return 1;
	MInt q = pot(b, e/2); q = q*q;
	return (e & 1 ? b*q : q);
}
MInt cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
MInt root(int n, bool inv){ // NTT
	MInt r=pot(RT,(MODNTT-1)/n); // pot: modular exponentiation
	return inv?pot(r,MODNTT-2):r;
}
void dft(MInt* a, int n, bool inv){
	forn(i,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for (int m=2;m<=n;m*=2){
		MInt wi=root(m,inv); // NTT
		for (int j=0;j<n;j+=m){
			MInt w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				MInt u=a[k]; MInt v=a[k2]*w; a[k]=u+v; a[k2]=u-v; w=w*wi;
			}
		}
	}
	if(inv){ // NTT
		MInt z(pot(n,MODNTT-2)); // pot: modular exponentiation
		forn(i,n)a[i]=a[i]*z;
	}
}
const int N = 5e4, M = 2*N;
vll multiply(vll& p1, vll& p2){
	int n=si(p1)+si(p2)+1;
    assert(n <= N);
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	forn(i,m){R[i]=0;forn(j,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forn(i,m)cp1[i]=0,cp2[i]=0;
	forn(i,si(p1)) cp1[i]=p1[i];
	forn(i,si(p2)) cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	forn(i,m) cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	vll res;
	n-=2;
	forn(i,n)res.pb(cp1[i].m); // change for NTT
	return res;
}

int n, m;
vi adj[N]; 
vii adjb[M];

bool isPrime[N];
void calcPrimes() {
    forsn(k, 2, N) {
        isPrime[k] = true;
        for (int d = 2; d*d <= k; d++) if (k % d == 0)
            isPrime[k] = false;
    }
}

bool taken[M];
int par[M];
int szt[M];
void calcsz(int v, int p) {
	szt[v] = 1;
	for (auto uc : adjb[v]) {
        int u = uc.fst;
        if (u!=p && !taken[u])
            calcsz(u,v), szt[v]+=szt[u];
    }
}
void processSubtree(int v);
void centroid(int v=0, int f=-1, int lvl=0, int tam=-1) {//O(nlogn)
	if (tam==-1) calcsz(v, -1), tam=szt[v];
	for (auto uc : adjb[v]) {
        int u = uc.fst;
        if (!taken[u] && szt[u]*2>=tam) { 
            szt[v]=0; 
            centroid(u, f, lvl, tam); 
            return;
        }
    }

    processSubtree(v);
    
	taken[v]=true;
	par[v]=f;
	for (auto uc : adjb[v]) {
        int u = uc.fst;
        if (!taken[u])
            centroid(u, v, lvl+1, -1);
    }
}

void binarize(int u = 0, int p = -1) {
    int act = u;
    for (int v : adj[u]) if (v != p) {
        adjb[act].pb(v, 1); adjb[v].pb(act, 1);
        binarize(v, u);

        int w = m++; 
        adjb[act].pb(w, 0); adjb[w].pb(act, 0);

        act = w;
    }
}

void getDistances(int u, vll &ds, int acum, int p) {
    if (u < n) ds[acum]++;

    for (auto vc : adjb[u]) {
        int v, c; tie(v, c) = vc;
        if (v != p && !taken[v])
            getDistances(v, ds, acum+c, u);
    }
}

/*
vll multiply(vll &a, vll &b) {
    vll res(si(a) + si(b) - 1);
    forn(i, si(a)) forn(j, si(b)) res[i+j] += a[i]*b[j];
    return res;
}
*/

ll primePaths = 0;
void checkDistances(vll &ds) {
    forn(d, si(ds)) if (isPrime[d]) primePaths += ds[d];
}

void processSubtree(int u) {
    calcsz(u, -1);

    forn(i, si(adjb[u])) {
        int v, c; tie(v, c) = adjb[u][i];
        if (taken[v]) continue;

        vll dsv(szt[v]+1); getDistances(v, dsv, c, u);
        if (u < n) checkDistances(dsv);

        forsn(j, i+1, si(adjb[u])) {
            int w; tie(w, c) = adjb[u][j];
            if (taken[w]) continue;

            vll dsw(szt[w]+1); getDistances(w, dsw, c, u);

            vll dsvw = multiply(dsv, dsw);

            checkDistances(dsvw);
        }
    }
}

int main() {
	fastio;

    calcPrimes();
	
    cin >> n;
    forn(_, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    } 

    m = n;
    binarize();

    centroid();

    ll paths = (ll)n*(n-1)/2;
    //cerr << primePaths << ' ' << paths << endl;
    cout << fixed << setprecision(6) << 1.*primePaths/paths << endl;
	
	return 0;
}
