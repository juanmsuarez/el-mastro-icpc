struct Matching {
    // Indicate whether each node is on the left or call bipartition
    int n;
    vi match;
    vector<vi> g;
    vector<bool> vis, left;

    void addEdge(int u, int v) { g[u].pb(v), g[v].pb(u); }

    Matching(int _n) : n(_n), match(n, -1), g(n), vis(n), left(n) {}

    bool dfs(int u) {
        if (vis[u]) return false;
        vis[u] = true;
        for (int v : g[u])
            if (match[v] == -1 || dfs(match[v])) 
                return match[v] = u, match[u] = v, true;
        return false;
    }

    int max_matching() { // O(N * M)
        int flow = 0;
        forn(i, n) if (left[i])
            vis.assign(n, 0), flow += dfs(i);
        return flow;
    }
    
    void clear() { forn(i, n) g[i].clear(), vis[i] = 0, match[i] = -1; }

    bool bipartition() {
        queue<int> q; 
        vi dist(n, -1);
        forn(i, n) if (dist[i] == -1) {
            q.push(i), dist[i] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (dist[u] & 1) left[u] = 1; 
                for (int v : g[u]) {
                    if (dist[v] == -1)
                        dist[v] = dist[u] + 1, q.push(v);
                    else if ((dist[u] & 1) == (dist[v] & 1))
                        return false; // graph isn't bipartite
                }
            }
        }
        return true;
    }
};
