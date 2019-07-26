#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
    #define endl '\n'
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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

	struct edge {
		int u,v,comp;
		bool bridge;
	};

set<pii>bridges;

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
				if(b[v] > d[u]){
                    e[ne].bridge = true;
                    bridges.emplace(min(e[ne].u,e[ne].v),max(e[ne].u,e[ne].v));
                } // bridge
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
}biconexas;

vector<vi> G;
struct blockcut{

    vi component;
    vector<bool>artpoint;
    void build(bridge comps){
        G= vector<vi>(comps.nbc);
        artpoint= vector<bool>(comps.n,false);
        component= vi(comps.n);//component[u]=nodo del block cut tree que representa a u
        forn(u,si(comps.adj)){
            if(comps.comp[u]>1){
                artpoint[u]=true;
                vi artcomps;
                for (int i:comps.adj[u]){
                    edge e = comps.e[i];
                    artcomps.pb(e.comp);
                    if(!si(G[e.comp])||G[e.comp].back()!=si(G))
                        G[e.comp].pb(si(G));
                }
                sort(all(artcomps));
                artcomps.erase(unique(all(artcomps)),artcomps.end());
                component[u]=si(G);
                G.pb(artcomps);
            }
        }
        //cerr << "marcando comp de cada nodo" << endl;
        for(edge e:comps.e){
            if(e.bridge &&!artpoint[e.u]&&!artpoint[e.v]){
                G = (vector<vi>){{1},{0}};
                component = (vi){0,1};
                return;
            }
            else{
                if(!artpoint[e.u])component[e.u]=e.comp;
                if(!artpoint[e.v])component[e.v]=e.comp;
            }
        }
        //cerr << "marcado listo" << endl;
    }
    void print(bridge c){
        cerr << "u pertenece a componente:" << endl;
        forn(i,si(component)){
            cerr << i+1 << ": " << component[i] << endl;
            cerr << c.comp[i] << endl;
        }
        cerr << "arcos:" << endl;
        forn(u,si(G)){
            for(int v:G[u]){ 
                cerr << u << " " << v << endl;
            }
        }
    }
}bct;

const int MAXN=200001;
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

bool checkInbetween(int a,int b,int c){
    int compa = bct.component[a],compb=bct.component[b],compc=bct.component[c];

    //cerr << " " << compa << " " << compb << " " << compc <<endl;
    //D(dist(compa,compb));D(dist(compa,compc));D(dist(compc,compb));
    return dist(compa,compb)==dist(compa,compc)+dist(compc,compb);
}

bool checkInbetween(int a,int b,int c,int d){
    int compa = bct.component[a],compb=bct.component[b],compc=bct.component[c],compd= bct.component[d];

    //cerr << " " << compa << " " << compb << " " << compc <<endl;
    //D(dist(compa,compb));
    //D(dist(compa,compc));D(dist(compd,compb));
    //D(dist(compa,compd));D(dist(compc,compb));
    int arts = bct.artpoint[c] + bct.artpoint[d];
    return (dist(compa,compb) == (dist(compa,compc)+dist(compd,compb)+arts)) ||
        (dist(compa,compb)==(dist(compa,compd)+dist(compc,compb)+arts));
}
int main() {
	fastio;
#ifdef LOCAL
    freopen("a.out","w",stdout);
#endif
	
    int n,m;
    cin >> n >> m;

    biconexas = bridge(n);
    forn(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        biconexas.addEdge(u,v);
    }
    biconexas.dfs();
    bct.build(biconexas);
    N=si(G);
    dfs(0);
    build();

    //bct.print(biconexas);

    int q;
    cin >> q;
    forn(i,q){
        int type, A,B,N1,N2;
        cin >> type >> A >> B >> N1;
        A--; B--; N1--;
        if(type==1){
            cin >> N2;
            N2--;
            if(bridges.count(mp(min(N1,N2),max(N1,N2)))==0)cout << "da" <<endl;
            else{
                if(checkInbetween(A,B,N1,N2))cout << "ne" << endl;
                else cout << "da" << endl;
            }
        }
        else{
            if(!bct.artpoint[N1])cout << "da" << endl;
            else{
                if(checkInbetween(A,B,N1))cout << "ne"<<endl;
                else cout << "da" <<endl;
            }
        }
    }
    


	
	return 0;
}

