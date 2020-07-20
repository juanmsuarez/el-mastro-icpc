struct MCF {
    const ll INF = 1e18;
    int n; vector<vi> adj;
    vector<vll> cap, cost;

    MCF(int _n) : n(_n) {
        adj.assign(n, vi());
        cap.assign(n, vll(n));
        cost.assign(n, vll(n));
    }

    void addEdge(int u, int v, ll _cap, ll _cost) {
        cap[u][v] = _cap;
        adj[u].pb(v), adj[v].pb(u);
        cost[u][v] = _cost, cost[v][u] = -_cost;
    }
    
    void shortest_paths(int s, vll &dist, vi &par) {
        par.assign(n, -1);
        vector<bool> inq(n);
        queue<int> q; q.push(s);
        dist.assign(n, INF), dist[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = false;
            for (int v : adj[u]) {
                if (cap[u][v] > 0 && dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v], par[v] = u;
                    if (!inq[v]) inq[v] = true, q.push(v);
                }
            }
        }
    }
    
    ll min_cost_flow(ll k, int s, int t) {
        vll dist; vi par; 
        ll flow = 0, total = 0;
        while (flow < k) {
            shortest_paths(s, dist, par);
            if (dist[t] == INF) break;
            // find max flow on that path
            ll f = k - flow;
            int cur = t;
            while (cur != s) {
                int p = par[cur];
                f = min(f, cap[p][cur]);
                cur = p;
            }
            // apply flow
            flow += f, total += f * dist[t], cur = t;
            while (cur != s) {
                int p = par[cur];
                cap[p][cur] -= f;
                cap[cur][p] += f;
                cur = p;
            }
        }
        return flow < k ? -1 : total;
    }
};    
