struct Dinic {
    struct Edge { int v, r; ll c, f=0; };
    vector<vector<Edge>> g; vi dist, ptr;
    static const ll INF = 1e18;
    int n, s, t; 
    Dinic(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t;
        g.resize(n), dist = vi(n), ptr = vi(n);
    }
    void addEdge(int u, int v, ll c1, ll c2=0) {
        g[u].pb((Edge){v, si(g[v]), c1});
        g[v].pb((Edge){u, si(g[u])-1, c2});
    }
    bool bfs() {
        fill(all(dist), -1), dist[s] = 0;
        queue<int> q({s}); 
        while (si(q)) {
            int u = q.front(); q.pop();
            for (auto &e : g[u])
                if (dist[e.v] == -1 && e.f < e.c)
                    dist[e.v] = dist[u] + 1, q.push(e.v);
        }
        return dist[t] != -1;
    }
    ll dfs(int u, ll cap = INF) {
        if (u == t) return cap;
        for (int &i = ptr[u]; i < si(g[u]); ++i) {
            auto &e = g[u][i];
            if (e.f < e.c && dist[e.v] == dist[u] + 1) {
                ll flow = dfs(e.v, min(cap, e.c - e.f));
                if (flow) {
                    e.f += flow, g[e.v][e.r].f -= flow;
                    return flow;
                }
            }
        }
        return 0;
    }
    ll maxflow() {
        ll res = 0;
        while (bfs()) {
            fill(all(ptr), 0);
            while (ll flow = dfs(s)) res += flow;
        }
        return res;
    }
    void reset() { for (auto &v : g) for (auto &e : v) e.f = 0; }
};
