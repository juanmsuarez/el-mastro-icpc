// We have one node for each boolean variable and other for its negation
// Every edge represents an implication, to add a clause (a or b), use add_or(a, b)
// val[comp[i]] = value of variable i
struct SAT {
    int n, id, comps, x;
    vi low, idx, comp;
    vector<bool> val;
    vector<vi> g;
    stack<int> q;

    SAT(int vars) : n(vars), low(2*n), val(2*n), g(2*n) { reset(); }
    void reset() { id = comps = 0, idx.assign(2*n, -1), comp.assign(2*n, -1); }
    int neg(int u) { return u >= n ? u-n : u+n; }

    void add_or(int a, int b) { g[neg(a)].pb(b), g[neg(b)].pb(a); }
    void add_implication(int a, int b) { g[a].pb(b), g[neg(b)].pb(neg(a)); }
    void fix_variable(int var) { g[neg(var)].pb(var); }

    void tarjan(int u) {
        low[u] = idx[u] = id++;
        q.push(u), comp[u] = -2;
        for (int v : g[u]) {
            if (idx[v] == -1 || comp[v] == -2) {
                if (idx[v] == -1) tarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (low[u] == idx[u]) {
            do { x = q.top(), q.pop(), comp[x] = comps; } while (x != u);
            val[comps++] = comp[neg(u)] < 0;
        }
    }

    bool satisfiable() {
        reset();
        forn(i, 2*n) if (idx[i] == -1) tarjan(i);
        forn(i, n) if (comp[i] == comp[neg(i)]) return false;
        return true;
    }
};
