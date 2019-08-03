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

const int MAXN=1e5+10;
const int LOGN=20;
vi G[MAXN];
//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int N, f[MAXN][LOGN], L[MAXN]; //INICIALIZAR N!!!!!!!!!!!!!!1
//call before build:
void dfs(int v, int fa=-1, int lvl=0){//generate required data
	f[v][0]=fa, L[v]=lvl;
	for(auto u: G[v])if(u!=fa) dfs(u, v, lvl+1); }
void build(){//f[i][0] must be filled previously, O(nlgn)
	forn(k, LOGN-1) forn(i, N) if (f[i][k]!=-1) f[i][k+1]=f[f[i][k]][k];}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
	if(!d) return a;
	dforsn(i,0, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;}
int lca(int a, int b){//O(lgn)
	if(L[a]<L[b]) swap(a, b);
	a=climb(a, L[a]-L[b]);
	if(a==b) return a;
	dforsn(i,0, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return f[a][0]; }
int dist(int a, int b) {//returns distance between nodes
	return L[a]+L[b]-2*L[lca(a, b)];}

int main() {
	fastio;
	
    int q; 
    cin >> N >> q;

    forn(_, N-1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    dfs(0);
    build();

    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;

        int lcaAB = lca(a, b), lcaCD = lca(c, d),
            u = L[lcaAB] <= L[lcaCD] ? lcaCD : lcaAB;

        vi vec;
        vec.pb(lca(a, c)); vec.pb(lca(a, d)); vec.pb(lca(b, c)); vec.pb(lca(b, d));
        sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

        int ans = 0, eq = 0, cnt = 0;

        for (int v : vec)
            if (L[v] > L[u]) { ans += L[v] - L[u] + 1; cnt++; }
            else if (L[v] == L[u]) eq++;

        if (eq > 0 && cnt == 0) ans = 1;
        if (cnt == 2) ans--; 

        cout << ans << endl;
    }    
	
	return 0;
}
