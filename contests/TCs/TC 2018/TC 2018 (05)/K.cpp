#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forn(i,n) forsn(i, 0, n)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define dforn(i,n) dforsn(i, 0, n)
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

const int MAXN = 800+10;
const ll INF = 1e18;
// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// MAXN Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// MAXN Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un MAXN Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el

// Tiempos! O(V^2*E) en general. O(sqrt(V)*E) en matching bipartito. O(min(V^(2/3), E^(1/2))*E) si capacidad 1.
int nodes, src, dst;
int dist[MAXN], q[MAXN], work[MAXN];
struct Edge {
    int to, rev;
    ll f, cap;
    Edge(int to, int rev, ll f, ll cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<Edge> G[MAXN];
void addEdge(int s, int t, ll cap) {
    G[s].pb(t, si(G[t]), 0, cap), G[t].pb(s, si(G[s])-1, 0, 0);
}
bool dinic_bfs(){
    fill(dist, dist+nodes, -1), dist[src]=0;
    int qt=0; q[qt++]=src;
    forn(qh, qt) {
        int u = q[qh];
        for (Edge e : G[u]) {
            int v=e.to;
            if(dist[v]<0 && e.f < e.cap)
                dist[v]=dist[u]+1, q[qt++]=v;
        }
    }
    return dist[dst]>=0;
}
ll dinic_dfs(int u, ll f){
    if(u==dst) return f;
    for(int &i=work[u]; i<si(G[u]); i++){
        Edge &e = G[u][i];
        if (e.cap<=e.f) continue;
        int v=e.to;
        if (dist[v]==dist[u]+1){
                ll df=dinic_dfs(v, min(f, e.cap-e.f));
                if (df>0) {
                        e.f+=df, G[v][e.rev].f-= df;
                        return df;  
                }
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
    return result; 
}
// IMPORTANTE!!! Recordar setear src, dst y nodes.

const int MAXNM = 400+10;
bool know[MAXNM][MAXNM];

int main() {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    while (k--) {
        int a, b; cin >> a >> b; a--; b--;
        know[a][b] = true;
    }

    nodes = n+m+2; src = nodes-2; dst = nodes-1;
    forn(a, n) forn(b, m) if (!know[a][b]) addEdge(a, n+b, INF);

    ll iqsum = 0;
    forn(a, n) {
        int iq; cin >> iq; iqsum += iq;
        addEdge(src, a, iq);
    }
    forn(b, m) {
        int iq; cin >> iq; iqsum += iq;
        addEdge(n+b, dst, iq);
    }

    cout << iqsum - maxFlow() << endl;

    vi v1; 
    forn(a, n) if (dist[a] > 0) v1.pb(a);
    cout << si(v1) << endl;
    forn(i, si(v1)) {
        if (i) cout << ' ';
        cout << v1[i]+1;
    } 
    cout << endl;

    vi v2;
    forn(b, m) if (dist[n+b] == -1) v2.pb(b);
    cout << si(v2) << endl;
    forn(i, si(v2)) {
        if (i) cout << ' ';
        cout << v2[i]+1;
    }
    cout << endl;

    return 0;
}
