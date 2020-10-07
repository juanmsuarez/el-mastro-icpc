// For values in nodes set the flag to false and load init values in val
template <class T>
struct HLD {
    vi par, heavy, depth, val, root, rmqPos;
    vector<vector<pii>> g; vector<pii> e; 
    RMQ<T> rmq; // requires seg tree
    bool valuesInEdges = true;
    int dfs(int u = 0) {
        int size = 1, mx = 0;
        for (auto [v, w] : g[u]) if (v != par[u]) {
            par[v] = u, depth[v] = depth[u] + 1;
            if (valuesInEdges) val[v] = w;
            int sz = dfs(v);
            if (sz > mx) heavy[u] = v, mx = sz;
            size += sz;
        }
        return size;
    }
    HLD(int n) : par(n, -1), heavy(n, -1), depth(n), 
        val(n), root(n), rmqPos(n), g(n), rmq(n) {}
    void addEdge(int u, int v, int w = 0) { 
        g[u].pb(v, w), g[v].pb(u, w), e.pb(u, v);
    }
    void build() {
        dfs(); 
        int pos = 0, n = si(g);
        forn(i, n) if (par[i] == -1 || heavy[par[i]] != i)
            for (int j = i; j != -1; j = heavy[j]) 
                root[j] = i, rmqPos[j] = pos++;
        for (auto &[u, v] : e) if (par[u] != v) swap(u, v);
        forn(i, n) rmq[rmqPos[i]] = val[i];
        rmq.build();
    }
    template <class Op>
    void processPath(int u, int v, Op op) {
        for (; root[u] != root[v]; v = par[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            op(rmqPos[root[v]], rmqPos[v] + 1);
        }
        if (valuesInEdges && u == v) return;
        if (depth[u] > depth[v]) swap(u, v);
        op(rmqPos[u] + valuesInEdges, rmqPos[v] + 1);
    }
    T query(int u, int v) {
        T res = T();
        processPath(u, v, [&](int l, int r) { res = res + rmq.get(l, r); });
        return res;
    }
    void set(int i, const T &x) { 
        rmq.set(rmqPos[valuesInEdges ? e[i].fst : i], x); 
    }
    void update(int u, int v, const T &x) { // requires lazy
        processPath(u, v, [&](int l, int r) { rmq.update(l, r, x); });
    }
    int lca(int u, int v) { // not needed
        for (; root[u] != root[v]; v = par[root[v]])
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
        return depth[u] > depth[v] ? v : u;
    }
};
