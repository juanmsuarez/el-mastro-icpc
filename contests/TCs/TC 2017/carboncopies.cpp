#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
    #define RAYA cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 2*300+10;
const tint INF = 1e18;
// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// MAXN Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// MAXN Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un MAXN Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el
int nodes, src, dst;
int dist[MAXN], q[MAXN], work[MAXN];
struct Edge {
    int to, rev;
    tint f, cap;
    Edge(int to, int rev, tint f, tint cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<Edge> G[MAXN];
void addEdge(int s, int t, tint cap) {
    //cerr << "arco " << s << ' ' << t << ' ' << cap << endl;
    G[s].eb(t, si(G[t]), 0, cap), G[t].eb(s, si(G[s])-1, 0, 0);
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
tint dinic_dfs(int u, tint f){
    if(u==dst) return f;
    for(int &i=work[u]; i<si(G[u]); i++){
        Edge &e = G[u][i];
        if (e.cap<=e.f) continue;
        int v=e.to;
        if (dist[v]==dist[u]+1){
                tint df=dinic_dfs(v, min(f, e.cap-e.f));
                if (df>0) {
                        e.f+=df, G[v][e.rev].f-= df;
                        return df;  
                }
        }
    }
    return 0;
}
tint maxFlow(){
    tint result=0;
    while(dinic_bfs()){
        fill(work, work+nodes, 0);
        while(tint delta=dinic_dfs(src,INF))
            result+=delta;
    }
    // todos los nodos con dist[v]!=-1 vs los que tienen dist[v]==-1 forman el min-cut
    return result; 
}
// IMPORTANTE!!! Recordar setear src y dst.

typedef vector<pii> vii;

map<string, int> h;
int name[2][MAXN];
vii adj[2][MAXN];

int main() {
    fastio;

    int N, M;
    while (cin >> N >> M) {
        //cerr << "start case " << endl;
        h.clear();
        forn(i, MAXN) {
            G[i].clear();
            forn(k, 2) adj[k][i].clear();
        }

        int cnt = 1;
        forn(k, 2) {
            forn(i, N) {
                string s;
                cin >> s;

                if (h.count(s) == 0)
                    h[s] = cnt++;

                name[k][i] = h[s];                
            }
            forn(_, M) {
                int a, b, c;
                cin >> a >> b >> c;
                a--; b--;

                adj[k][a].eb(b, c);
                adj[k][b].eb(a, c);
            }
        }

        //cerr << "read" << endl;

        forn(k, 2) forn(i, N) 
            sort(all(adj[k][i]), [k](pii a, pii b) {
                return name[k][a.first] < name[k][b.first] || 
                    (name[k][a.first] == name[k][b.first] && a.second < b.second);
            });

        nodes = 2*N+2, src = 2*N, dst = 2*N+1;

        forn(i, N) addEdge(src, i, 1), addEdge(N+i, dst, 1);

        forn(i, N) {
            forn(j, N) {
                //cerr << i << ' ' << j << endl;
                //cerr << "names " <<  name[0][i] << ' ' << name[1][j] << endl;
                //cerr << "sz " << si(adj[0][i]) << ' ' << si(adj[1][j]) << endl; 
                if (name[0][i] == name[1][j] && si(adj[0][i]) == si(adj[1][j])) {
                    bool can = true;

                    forn(k, si(adj[0][i])) {
                        //cerr << "adjs " << adj[0][i][k].first << ' ' << adj[1][j][k].first << endl;
                        int v0 = adj[0][i][k].first, v1 = adj[1][j][k].first;
                        int c0 = adj[0][i][k].second, c1 = adj[1][j][k].second;
                        if (name[0][v0] != name[1][v1] || c0 != c1)
                            can = false;
                    }

                    if (can)
                        addEdge(i, N+j, 1);
                }
            }
        }

        //cerr << "graph rdy" << endl;

        cout << (maxFlow() == N ? "EQUAL" : "NOT EQUAL") << endl;
    }

    return 0;
}
