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
#define aint(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = 3e3+10;

// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// MAXN Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// MAXN Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un MAXN Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el

// Tiempos! O(V^2*E) en general. O(sqrt(V)*E) en matching bipartito. O(min(V^(2/3), E^(1/2))*E) si capacidad 1.
template<int MAXN>
struct dinic {

    struct edge {
        int u,v; int c,f;
        int r() { return c-f; }
    };

    static const int INF = 1e9;

    int N,S,T;
    vector<edge> e;
    //edge red[MAXN][MAXN];
    vi adjG[MAXN], pre;

    dinic() { }

    dinic(dinic &d) {
        N = d.N, S = d.S, T = d.T;
        e = d.e;
        pre = d.pre;
        forn(u, MAXN) adjG[u] = d.adjG[u];
    }

    void reset() {
        forn(u,N) for (auto ind : adjG[u]) {
            auto &ei = e[ind];
            ei.f = 0;
        }
    }

    void initGraph(int n, int s, int t) {
        N = n; S = s; T = t;
        e.clear();
        pre = vi(n);
        forn(u,N) adjG[u].clear();
    }

    void addEdge(int u, int v, int c) {
        if (u == S) pre[v] = si(e);
        adjG[u].pb(si(e)); e.pb((edge){u,v,c,0});
        adjG[v].pb(si(e)); e.pb((edge){v,u,0,0});
    }

    int dist[MAXN];
    bool dinic_bfs() {
        forn(u,N) dist[u] = -1;
        queue<int> q; q.push(S); dist[S] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto ind : adjG[u]) {
                auto &ei = e[ind];
                int v = ei.v;
                if (dist[v] != -1 || ei.r() == 0) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return dist[T] != -1;
    }

    int dinic_dfs(int u, int cap) {
        if (u == T) return cap;

        int res = 0;
        for (auto ind : adjG[u]) {
            auto &ei = e[ind], &ej = e[ind^1];
            int v = ei.v;
            if (ei.r() && dist[v] == dist[u] + 1) {
                int send = dinic_dfs(v,min(cap, ei.r()));
                ei.f += send; ej.f -= send;
                res += send; cap -= send;
                if (cap == 0) break;
            }
        }
        if (res == 0) dist[u] = -1;
        return res;
    }

    int flow() {
        int res = 0;
        while (dinic_bfs()) res += dinic_dfs(S,INF);
        return res;
    }
};

int main() {
	fastio;
	
    int m, n, k; cin >> m >> n >> k;
    
    dinic<MAXN> d;
    d.initGraph(n+m+2, n+m, n+m+1);

    forn(a, m) d.addEdge(d.S, a, 1);
    forn(b, n) d.addEdge(m+b, d.T, 1);

    while (k--) {
        int a, b; cin >> a >> b; a--, b--;

        d.addEdge(a, m+b, 1);
    }    

    int basic = d.flow(), ans = basic;

    forn(a, m) {
        dinic<MAXN> act = d;
        act.e[act.pre[a]].c += 2;

        ans = max(ans, basic+act.flow()); 
    }

    cout << ans << endl;
	
	return 0;
}
