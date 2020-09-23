struct DSU {
    int comps; vi par, sz, c;
    DSU(int n): comps(n), par(n), sz(n, 1) { iota(all(par), 0); }
    int find(int u) { return u == par[u] ? u : find(par[u]); }
    bool join(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return false;        
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v], par[v] = u, comps--, c.pb(v);
        return true;
    }
    int snap() { return si(c); }
    void rollback(int snap){
        while (si(c) > snap) {
            int v = c.back(); c.pop_back();
            sz[par[v]] -= sz[v], par[v] = v, comps++;
        }
    }
};
struct DynCon { // O((m + q) * lg q * lg n)
    vi match, ans, from, to; int sz = 0;
    map<pii, int> last; DSU dsu; 
    DynCon(int n): dsu(n) {}
    void add(int u, int v) {
        if (u > v) swap(u, v);
        from.pb(u), to.pb(v), match.pb(-2), last[{u, v}] = sz++;
    }
    void del(int u, int v) {
        if (u > v) swap(u, v);
        int p = last[{u, v}]; from.pb(u), to.pb(v), match[p] = sz++, match.pb(p);
    }
    void query() { from.pb(0), to.pb(0), match.pb(-1), sz++; } // make at least one
    void process() { // call after all queries, they're answered in order
        forn(i, sz) if (match[i] == -2) match[i] = sz;
        go(0, sz);
    }
    void go(int l, int r) {
        if (l+1 == r) {
            if (match[l] == -1) ans.pb(dsu.comps); // query: connected components
            return;
        }
        int m = (l + r) / 2, s = dsu.snap(); 
        forsn(i, m, r) if (match[i] < l && match[i] != -1) dsu.join(from[i], to[i]);
        go(l, m), dsu.rollback(s);
        forsn(i, l, m) if (match[i] >= r) dsu.join(from[i], to[i]);
        go(m, r), dsu.rollback(s);
    }
};
