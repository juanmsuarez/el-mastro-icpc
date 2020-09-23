struct DSU {
    vi par, sz;
    DSU(int n): par(n), sz(n, 1) { iota(all(par), 0); }
    int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
    bool connected(int u, int v) { return find(u) == find(v); }
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) par[u] = v, sz[v] += sz[u];
        else par[v] = u, sz[u] += sz[v];
        return true;
    }
};
