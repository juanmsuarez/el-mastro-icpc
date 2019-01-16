#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forn(i,n) forsn(i, 0, n)
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
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 1e5+10;

int M, eulerM, ans = 0;

// MOD
int add(int a, int b) {
    if (a+b >= M) return a+b-M;
    return a+b;
}
int mult(int a, int b) {
    return (ll)a*b%M;
}
int neg(int a) {
    return add(-a, M);
}

// EULER PHI
int eulerPhi (int n) {
    int result=n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result -= result / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

// INVERSO
int inv[MAXN];
ll expmod(ll b, ll e){ // O(log e)
	if(!e) return 1;
	ll q = expmod(b, e/2); q = mult(q,q);
	return (e % 2 ? mult(b,q) : q);
}
int inverso(int x){//O(log x)
	return expmod(x, eulerM-1);
}
void calcinversos(int n) {
    int pot = 1;
    eulerM = eulerPhi(M);
    forn(i, n) {
        inv[i] = inverso(pot);
        pot = mult(pot, 10);
    }
}

// CENTROID
vector<int> G[MAXN];
bool taken[MAXN];//poner todos en FALSE al principio!!
int szt[MAXN], l[MAXN];
void calcsz(int v, int p) {
	szt[v] = 1;
	for (int u : G[v]) if (u!=p && !taken[u])
		calcsz(u,v), szt[v]+=szt[u];
}
void work(int u);
void centroid(int v=0, int f=-1, int lvl=0, int tam=-1) {//O(nlogn)
	if(tam==-1)	calcsz(v, -1), tam=szt[v];
	for(int u : G[v]) if(!taken[u] && szt[u]>=tam/2)
		{szt[v]=0; centroid(u, f, lvl, tam); return;}
    work(v);
	taken[v]=true;
	for(int u : G[v]) if(!taken[u])
		centroid(u, v, lvl+1, -1);
}

// SOLUTION
vector<pii> adj[MAXN]; ll cnt1 = 0, cnt2 = 0;
void query(int u, int p, int num, int pot, map<int,int> &m) {
    cnt1 += m[neg(mult(num, inv[pot]))];
    if (num == 0) cnt2++;

    for (pii e : adj[u]) {
        int v = e.first, d = e.second;
        if (v == p || taken[v]) continue;
        query(v, u, add(mult(num, 10), d), pot+1, m);
    }
}
void update(int u, int p, int num, int pot, map<int,int> &m) {
    m[num]++;
    if (num == 0) cnt2++;

    for (pii e : adj[u]) {
        int v = e.first, d = e.second;
        if (v == p || taken[v]) continue;
        update(v, u, add(mult(pot, d), num), mult(pot, 10), m);
    }
}

void visit(int u) {
    map<int,int> m;

    for (pii e : adj[u]) {
        int v = e.first, d = e.second;
        if (taken[v]) continue;

        query(v, u, d, 1, m);
        update(v, u, d, 10, m);
    }
}

void work(int u) {
    visit(u);
    reverse(all(adj[u]));
    visit(u);
    reverse(all(adj[u]));
}

int main() {
    fastio;

    int n;
    cin >> n >> M;
    calcinversos(n);
    forn(i, n-1) {
        int u, v, d;
        cin >> u >> v >> d; d%=M;
        G[u].pb(v); G[v].pb(u);
        adj[u].pb(v, d); adj[v].pb(u, d);
    }    

    centroid(); 

    cout << cnt1 + cnt2/2 << endl;

    return 0;
}
