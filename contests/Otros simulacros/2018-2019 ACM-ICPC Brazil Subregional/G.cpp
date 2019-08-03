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

template<int MAXN>
struct dinic {

    struct edge {
        int u,v; ll c,f;
        ll r() { return c-f; }
    };

    static const ll INF = 1e18;

    int N,S,T;
    vector<edge> e;
    //edge red[MAXN][MAXN];
    vi adjG[MAXN];

    void reset() {
        forn(u,N) for (auto ind : adjG[u]) {
            auto &ei = e[ind];
            ei.f = 0;
        }
    }

    void initGraph(int n, int s, int t) {
        N = n; S = s; T = t;
        e.clear();
        forn(u,N) adjG[u].clear();
    }

    void addEdge(int u, int v, ll c) {
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

    ll dinic_dfs(int u, ll cap) {
        if (u == T) return cap;

        ll res = 0;
        for (auto ind : adjG[u]) {
            auto &ei = e[ind], &ej = e[ind^1];
            int v = ei.v;
            if (ei.r() && dist[v] == dist[u] + 1) {
                ll send = dinic_dfs(v,min(cap, ei.r()));
                ei.f += send; ej.f -= send;
                res += send; cap -= send;
                if (cap == 0) break;
            }
        }
        if (res == 0) dist[u] = -1;
        return res;
    }

    ll flow() {
        ll res = 0;
        while (dinic_bfs()) res += dinic_dfs(S,INF);
        return res;
    }

    vi cut() {
        dinic_bfs();
        vi ans;
        for (auto u : adjG[S]) if (dist[e[u].v] == -1) ans.pb(e[u].v);
        for (auto u : adjG[T]) if (dist[e[u].v] != -1) ans.pb(e[u].v);
        return ans;
    }

    vi indep() {
        dinic_bfs();
        vi ans;
        for (auto u : adjG[S]) if (dist[e[u].v] != -1) ans.pb(e[u].v);
        for (auto u : adjG[T]) if (dist[e[u].v] == -1) ans.pb(e[u].v);
        return ans;
    }
};

typedef tuple<int,int,int> edge;

const int MAXN = 2e3+10, INF = 1e9;
dinic<MAXN> d;
int na, nb, m, need[MAXN], have[MAXN], sumNeed = 0; 
vector<edge> ve;
bool can(int T) {
    int nodes = na+nb+2;
    d.initGraph(nodes, nodes-2, nodes-1);

    forn(u, na) d.addEdge(d.S, u, have[u]);
    forn(v, nb) d.addEdge(na+v, d.T, need[v]);

    for (edge &e : ve) {
        int t, u, v; tie(t, u, v) = e;
        if (t <= T) d.addEdge(u, na+v, INF);
    }

    return d.flow() >= sumNeed;
}

int main() {
	fastio;
	
    cin >> nb >> na >> m;
    forn(i, nb) { cin >> need[i]; sumNeed += need[i]; }
    forn(i, na) cin >> have[i];

    forn(_, m)  {
        int u, v, t; cin >> v >> u >> t; u--, v--;
        ve.pb(t, u, v);
    }


    int lo = 0, hi = 1e6;
    if (!can(hi)) { cout << -1 << endl; return 0; }
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;

        if (can(mid)) hi = mid;
        else lo = mid;
    }

    cout << hi << endl;
	
	return 0;
}
