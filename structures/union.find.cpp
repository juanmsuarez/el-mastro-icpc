struct UF {
    vi par, size;
    UF(int n): par(n), size(n, 1) { iota(all(par), 0); }
    int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
    bool connected(int u, int v) { return find(u) == find(v); }
    bool join(int u, int v) {
        if (connected(u, v)) return false;
        u = find(u), v = find(v);

        if (size[u] < size[v]) par[u] = v, size[v] += size[u];
        else par[v] = u, size[u] += size[v];
        return true;
    }
};
