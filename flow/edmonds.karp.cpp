struct EK {
    vector<vi> g; vector<vector<ll>> cap;
    static const ll INF = 1e18;
    int n, s, t; vi par;
    EK(int _n, int _s, int _t) {
        n = _n, s = _s, t = _t;
        par = vi(n), g.resize(n);
        cap.assign(n, vector<ll>(n));
    }
    void addEdge(int u, int v, ll c) {
        g[u].pb(v), g[v].pb(u), cap[u][v] = c;
    }
    ll bfs() {
        fill(all(par), -1), par[s] = s;
        queue<pair<int, ll>> q({{s, INF}});
        while (si(q)) {
            auto [u, f] = q.front(); q.pop();
            for (int v : g[u]) {
                if (par[v] == -1 && cap[u][v]) {
                    par[v] = u;
                    ll flow = min(f, cap[u][v]);
                    if (v == t) return flow;
                    q.emplace(v, flow);
                }
            }
        }
        return 0;
    }
    ll maxflow() {
        ll res = 0;
        while (ll flow = bfs()) {
            res += flow;
            int cur = t;
            while (cur != s) {
                int prev = par[cur];
                cap[prev][cur] -= flow;
                cap[cur][prev] += flow;
                cur = prev;
            }
        }
        return res;
    }
};
