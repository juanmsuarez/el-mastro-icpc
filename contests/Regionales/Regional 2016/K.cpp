#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
    #define endl '\n'
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;
typedef long long ll;
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define sz(v) ((int)v.size())
#define INF 1e18

const int MAX = 300;
// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// Max Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// Max Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un Max Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el
int nodes, src, dst;
int dist[MAX], q[MAX], work[MAX];
struct Edge {
    int to, rev;
    ll f, cap;
    Edge(int to, int rev, ll f, ll cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<Edge> G[MAX];
void addEdge(int s, int t, ll cap){
    G[s].pb(Edge(t, sz(G[t]), 0, cap)), G[t].pb(Edge(s, sz(G[s])-1, 0, 0));}
bool dinic_bfs(){
    fill(dist, dist+nodes, -1), dist[src]=0;
    int qt=0; q[qt++]=src;
    for(int qh=0; qh<qt; qh++){
        int u =q[qh];
        forall(e, G[u]){
            int v=e->to;
            if(dist[v]<0 && e->f < e->cap)
                dist[v]=dist[u]+1, q[qt++]=v;
        }
    }
    return dist[dst]>=0;
}
ll dinic_dfs(int u, ll f){
    if(u==dst) return f;
    for(int &i=work[u]; i<sz(G[u]); i++){
        Edge &e = G[u][i];
        if(e.cap<=e.f) continue;
        int v=e.to;
        if(dist[v]==dist[u]+1){
                ll df=dinic_dfs(v, min(f, e.cap-e.f));
                if(df>0){
                        e.f+=df, G[v][e.rev].f-= df;
                        return df;  }
        }
    }
    return 0;
}
ll maxFlow(){
    ll result=0;
    while(dinic_bfs()){
        fill(work, work+nodes, 0);
        while(ll delta=dinic_dfs(src,INF))
            result+=delta;
    }
    // todos los nodos con dist[v]!=-1 vs los que tienen dist[v]==-1 forman el min-cut
    return result; }
 
void clearGraph() {
    forn(u, nodes)
        G[u].clear();
}

void initGraph(int _nodes, int _src, int _dst) {
    nodes = _nodes;
    src = _src;
    dst = _dst;

    clearGraph();
}

int main() {
	fastio;

	#ifdef LOCAL
 	       freopen("input.in","r",stdin);
	#endif
    
    int n;
    while(cin >> n){
        int res=0;
        vector<pii> seq(n);
        forn(i,n){
            cin >>seq[i].first>> seq[i].second;
            seq[i].first--;
            seq[i].second--;
        }
        forn(i,n){
            initGraph(2*n+2, 2*n, 2*n+1);
            int votes=0;
            forn(j,n){
                if(seq[j].first==i||seq[j].second==i)votes++;
            }
            forn(j,n){
                if(j!=i&&!(seq[j].first==i||seq[j].second==i)){
                    addEdge(src,j,1);
                    addEdge(j,n+seq[j].first,1);
                    addEdge(j,n+seq[j].second,1);
                }
            }
            forsn(j,n,2*n){
                if(seq[i].first==j-n||seq[i].second==j-n)addEdge(j,dst,votes-2);
                else addEdge(j,dst,votes-1);
            }
            if(maxFlow()+votes+1<n)res++;
        }
        cout << res << endl;

    }

	return 0;
}
