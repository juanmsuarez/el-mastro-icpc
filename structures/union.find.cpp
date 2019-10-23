struct UF {
    vi par, si;
    UF(int n) { par.resize(n), iota(all(par), 0), si.assign(n, 1); }
    int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
    bool connected(int u, int v) { return find(u) == find(v); }
    bool join(int u, int v) {
    	u = find(u), v = find(v);
        if (connected(u, v)) return false;

    	if (si[u] < si[v]) par[u] = v, si[v] += si[u];
    	else par[v] = u, si[u] += si[v];
        return true;
    }
};
