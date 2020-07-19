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
