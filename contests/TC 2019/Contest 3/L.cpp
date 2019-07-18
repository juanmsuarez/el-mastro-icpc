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

	struct edge {
		int u,v,comp;
		bool bridge;
	};
struct bridge {

	int n,t,nbc;//nbc= number of biconnected components
	vi d,b,comp;
    //d[i]=id de la dfs
    //b[i]=lowest id reachable from i
    //comp[i] = cant de componentes biconexas a las que pertenece i
	stack<int> st;
    vector<vi> adj;
	vector<edge> e;

	bridge(int n=0): n(n) {
		adj = vector<vi>(n);
		e.clear();
		initDfs();
	}

	void initDfs() {
        d = vi(n), b = vi(n), comp = vi(n);
        forn(i,n) d[i] = -1;
        nbc = t = 0;
	}

	void addEdge(int u, int v) {
		adj[u].pb(si(e)); adj[v].pb(si(e));
		e.pb((edge){u,v,-1,false});
	}

	void dfs(int u=0, int pe=-1) {
		b[u] = d[u] = t++;
        comp[u] = pe != -1;

		for(int ne : adj[u]) {
			if(ne == pe) continue; 
			int v = e[ne].u ^ e[ne].v ^ u;
			if(d[v] == -1) {
				st.push(ne);
				dfs(v,ne);
				if(b[v] > d[u]) e[ne].bridge = true; // bridge
				if(b[v] >= d[u]) { // art
					int last;
					do {
						last = st.top(); st.pop();
						e[last].comp = nbc;
					} while(last != ne);
					nbc++, comp[u]++;
				} 
				b[u] = min(b[u], b[v]);
			}
			else if(d[v] < d[u]) { // back edge
				st.push(ne);
				b[u] = min(b[u], d[v]);
			}
		}
	}
}compb;

struct blockcut{

    vector<vi> adjList;
    vi component;
    vector<bool>artpoint;
    void build(bridge comps){
        adjList= vector<vi>(comps.nbc);
        artpoints= vector<bool>(comps.nbc,false);
        component= vi(comps.nbc);
        forn(u,si(comps.adj)){
            if(comps.comp[u]>1){
                vi artcomps;
                for(int i:comps.adj[u]){
                    edge e = comps.e[i];
                    artcomps.pb(e.comp);
                    if(!si(adjList[e.comp])||adjList[e.comp].back()!=si(adjList))
                        adjList[e.comp].pb(si(adjList));
                }
                sort(all(artcomps));
                artcomps.erase(unique(all(artcomps)),artcomps.end());
                artpoints.pb(si(adjList));
                component[u]=si(adjList);
                adjList.pb(artcomps);
            }
        }
    }
};

const int MAXN=100001;
const int LOGN=20;
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
	
    int n,e;
    cin >> n >> e;

    forn(i,e){
        int u,v;
        cin >> u >> v;
        compb.addEdge(u,v);
    }
    

    


	
	return 0;
}

