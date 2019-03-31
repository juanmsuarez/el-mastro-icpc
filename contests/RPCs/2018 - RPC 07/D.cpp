#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(ll i=0;i<ll(n);i++)
#define forsn(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)
#define dforsn(i,s,n) for(ll i=(ll)((n)-1);i>=ll(s);i--)
#define si(a) ll((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) //cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const ll MAXM = 600+10;
const ll INFLL = 1e18;
// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// MAXM Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// MAXM Clique: construir la red de G complemento (dpbe ser bipartito!) y encontrar un MAXM Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el

// Tiempos! O(V²E) en general. O(sqrt(V)*E) en matching bipartito. O(min(V^(2/3), E^(1/2))*E) si capacidad 1.
ll nodes, src, dst;
ll dist[MAXM], q[MAXM], work[MAXM];
struct Edge {
    ll to, rev;
    ll f, cap;
    Edge(ll to, ll rev, ll f, ll cap) : to(to), rev(rev), f(f), cap(cap) {}
};
vector<Edge> G[MAXM];
void addEdge(ll s, ll t, ll cap) {
    G[s].pb(t, si(G[t]), 0, cap), G[t].pb(s, si(G[s])-1, 0, 0);
}
bool dinic_bfs(){
    fill(dist, dist+nodes, -1), dist[src]=0;
    ll qt=0; q[qt++]=src;
    forn(qh, qt) {
        ll u = q[qh];
        for (Edge e : G[u]) {
            ll v=e.to;
            if(dist[v]<0 && e.f < e.cap)
                dist[v]=dist[u]+1, q[qt++]=v;
        }
    }
    return dist[dst]>=0;
}
ll dinic_dfs(ll u, ll f){
    if(u==dst) return f;
    for(ll &i=work[u]; i<si(G[u]); i++){
        Edge &e = G[u][i];
        if (e.cap<=e.f) continue;
        ll v=e.to;
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
        while(ll delta=dinic_dfs(src,INFLL))
            result+=delta;
    }
    // todos los nodos con dist[v]!=-1 vs los que tienen dist[v]==-1 forman el min-cut
    return result; 
}
// IMPORTANTE!!! Recordar setear src, dst y nodes.
const double EPS=1e-9;
struct pto{
	ll x, y;
	pto(ll x=0, ll y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(ll a){return pto(x+a, y+a);}
	pto operator*(ll a){return pto(x*a, y*a);}
	pto operator/(ll a){return pto(x/a, y/a);}
	//dot product, producto llerno:
	ll operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	ll operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x || (abs(x-a.x)==0 && y<a.y);}
bool operator==(pto a){return abs(x-a.x)==0 && abs(y-a.y)==0;}
	ll norm_sq(){return x*x+y*y;}
};
ll dist_sq(pto a, pto b){return (b-a).norm_sq();}

const ll MAXN = 250+10, INF = 1e9;
ll n, b, r;
pto bs[MAXN], rs[MAXN];

bool can(ll d) {
    forn(i, MAXM) G[i].clear();

    src = r+b;
    dst = r+b+1;
    nodes = r+b+2;

    forn(i, b) addEdge(src, i, 1);
    forn(j, r) addEdge(b+j, dst, 1);

    forn(i, b)
        forn(j, r) {
            if (dist_sq(bs[i], rs[j]) < d) {
            //cerr << i << ' ' << j << ' ' << dist_sq(bs[i], rs[j]) << ' ' << d << endl;
                addEdge(i, b+j, INF);
            }
        }


    ll ans = r+b-maxFlow();
    //cerr << d << ' ' << ans << ' ' << n << endl;
    return ans >= n;
}

int main() {
    fastio;

    cin >> n >> b >> r;

    forn(i, b) cin >> bs[i].x >> bs[i].y;
    forn(i, r) cin >> rs[i].x >> rs[i].y;

    ll lo = 0, hi = INF;
    while (hi-lo > 1) {
        //cerr << lo << ' ' << hi << endl;
        ll mid = (lo+hi)/2;

        if (can(mid)) lo = mid;
        else hi = mid;
    }

    cout << fixed << setprecision(6) << sqrt(lo) << endl;

    return 0;
}
