#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
    #define cerrTime cerr << double(clock() - start)/CLOCKS_PER_SEC << endl
#else
    #define cerrTime
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

clock_t start;

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

	bridge(int _n=0): n(_n) {
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
#define MAXN 200000+10

vi G[MAXN];
int N;
struct blockcut{

    int repre[MAXN]; //repre[u]=nodo del block cut tree que representa a u
    bitset<MAXN>artpoint;
    void build(const bridge & comps){
        fill(G,G+MAXN,vi(0));
        fill(repre,repre+MAXN,-1);
        artpoint.reset();
        int ind =comps.nbc;
        for(edge e:comps.e){
            vi ed = {e.u,e.v};
            for(int w:ed){
                if(comps.comp[w]>1){
                    if(repre[w]==-1){
                        artpoint[w]=true;
                        repre[w]=ind++;
                    }
                    G[repre[w]].pb(e.comp);
                    G[e.comp].pb(repre[w]);
                }
                else repre[w]=e.comp;
            }
        }
        N=ind;
        forn(i,N){
            sort(all(G[i]));
            G[i].erase(unique(all(G[i])),G[i].end()); 
        }
        //cerr << "marcado listo" << endl;
    }
}bct;

const int LOGN=20;
//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int  f[MAXN][LOGN], L[MAXN]; //INICIALIZAR N!!!!!!!!!!!!!!1
//call before build:
void dfs(int v, int fa=-1, int lvl=0){//generate required data
    TDesc
    f[v][0]=fa, L[v]=lvl;
    for(auto u: G[v])if(u!=fa) dfs(u, v, lvl+1); 
}
void build(){//f[i][0] must be filled previously, O(nlgn)
    forn(k, LOGN-1) forn(i, N) if (f[i][k]!=-1) f[i][k+1]=f[f[i][k]][k];
}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
    if(!d) return a;
    dforsn(i,0, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;
}
int lca(int a, int b){//O(lgn)
    if(L[a]<L[b]) swap(a, b);
    a=climb(a, L[a]-L[b]);
    if(a==b) return a;
    dforsn(i,0, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
    return f[a][0]; 
}
int dist(int a, int b) {//returns distance between nodes
    return L[a]+L[b]-2*L[lca(a, b)];
}

bool checkInbetween(int a,int b,int c){
    int compa = bct.repre[a],compb=bct.repre[b],compc=bct.repre[c]; 
    int ablca = lca(compa,compb);
    //cerr << " " << compa << " " << compb << " " << compc <<endl;
    //D(dist(compa,compb));D(dist(compa,compc));D(dist(compc,compb));
    return dist(compa,compb)==dist(compa,compc)+dist(compc,compb);
}

bool checkInbetween(int a,int b,int c,int d){
    int compa = bct.repre[a],compb=bct.repre[b],compc=bct.repre[c],compd= bct.repre[d]; 
    //cerr << " " << compa << " " << compb << " " << compc <<endl;
    //D(dist(compa,compb));
    //D(dist(compa,compc));D(dist(compd,compb));
    //D(dist(compa,compd));D(dist(compc,compb));
    int arts = bct.artpoint[c] + bct.artpoint[d];
    int distab = dist(compa,compb);
    return (distab == (dist(compa,compc)+dist(compd,compb)+arts)) ||
        (distab==(dist(compa,compd)+dist(compc,compb)+arts));
}
int main() {
#ifdef LOCAL
    freopen("a.out","w",stdout);
    start = clock();
#endif


    int n,m;
    scanf("%d %d",&n,&m);

    biconexas = bridge(n);
    forn(i,m){
        int u,v;
        scanf("%d %d",&u,&v);
        u--; v--;
        biconexas.addEdge(u,v);
    }
    cerrTime;
    biconexas.dfs();
    cerrTime;
    bct.build(biconexas);
    cerrTime;
    dfs(0);
    cerrTime;
    build();
    cerrTime;

    //bct.print(biconexas);
#define yes "yes"
#define no "no"


    int q;
    scanf("%d",&q);
    forn(i,q){
        int type, A,B,N1,N2;
        scanf("%d %d %d %d",&type,&A,&B,&N1);
        A--; B--; N1--;
        if(type==1){
            scanf("%d",&N2);
            N2--;
            if(bridges.count(mp(min(N1,N2),max(N1,N2)))==0)puts(yes);
            else{
                if(checkInbetween(A,B,N1,N2))puts(no);
                else puts(yes);
            }
        }
        else{
            if(!bct.artpoint[N1])puts(yes);
            else{
                if(checkInbetween(A,B,N1))puts(no);
                else puts(yes);
            }
        }
    }
    cerrTime;




    return 0;
}
