struct UF {
    int n, comp;
    vi par, size, c;
    UF(int n = 0): n(n), comp(n), par(n), size(n, 1) { iota(all(par), 0); }
    int find(int u) { return u == par[u] ? u : find(par[u]); }
    bool connected(int u, int v) { return find(u) == find(v); }
    bool merge(int u, int v) {
        if (connected(u, v)) return false;        
        u = find(u), v = find(v);

        if (size[u] < size[v]) swap(u, v);
        size[u] += size[v], par[v] = u, comp--, c.pb(v);
        return true;
    }
    int snap() { return si(c); }
    void rollback(int snap){
        while (si(c) > snap) {
            int v = c.back(); c.pop_back();
            size[par[v]] -= size[v], par[v] = v, comp++;
        }
    }
};
enum { ADD, DEL, QUERY };
struct Query { int type, u, v; };
struct DynCon {
    vector<Query> q;
    UF uf;
    vi match; // match[i] = remove j asociado al add i (y viceversa)
    map<pii, int> last; // last[{u, v}] = i tal que add i agrega {u, v}
    vi res;
    DynCon(int n=0): uf(n) {}
    void add(int u, int v) {
        if (u > v) swap(u, v);
        q.pb((Query){ADD, u, v}), match.pb(-1), last[{u, v}] = si(q) - 1;
    }
    void remove(int u, int v) {
        if (u > v) swap(u, v);
        q.pb((Query){DEL, u, v});
        int prev = last[{u, v}]; match[prev] = si(q) - 1; match.pb(prev);
    }
    void query() {
        q.pb((Query){QUERY, -1, -1}), match.pb(-1);
    }
    void process() { // answers all queries in order
        if (q.empty()) return;
        forn(i, si(q)) if (q[i].type == ADD && match[i] == -1) match[i] = si(q);
        go(0, si(q));
    }
    void go(int l, int r) { // divide intervalo al medio y procesa por partes, O(k log k)
        if (l+1 == r) {
            if (q[l].type == QUERY) // answer query using UF 
                res.pb(uf.comp); // aqui query=cantidad de componentes conexas
            return;
        }
        int m = (l+r) / 2;

        int s = uf.snap(); 
        dforsn(i, m, r) if (match[i] != -1 && match[i] < l) uf.merge(q[i].u, q[i].v);
        go(l, m); uf.rollback(s);

        s = uf.snap();
        dforsn(i, l, m) if (match[i] != -1 && match[i] >= r) uf.merge(q[i].u, q[i].v);
        go(m, r); uf.rollback(s);
    }
};

// Primero agregar queries, adds y removes, luego llamar a process
