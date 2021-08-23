// We have one node for each boolean variable and other for its negation
// Every edge represents an implication, to add a clause (a or b), use add_or(a, b)
// val[comp[i]] = value of variable i
struct SAT {
    vector<vi> g;
    stack<int> q;
    vector<bool> val;
    vi low, idx, comp;
    int n, id, comps, x;

    SAT(int vars) {
        n = vars, g.resize(2*n), id = 0, comps = 0;
        low = vi(2*n), idx = vi(2*n, -1), comp = vi(2*n, -1);
    }

    int neg(int u) { return u >= n ? u-n : u+n; }
    void add_or(int a, int b) { g[neg(a)].pb(b), g[neg(b)].pb(a); }

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
            val.pb(comp[neg(u)] < 0), comps++;
        }
    }

    bool satisfiable() {
        forn(i, 2*n) if (idx[i] == -1) tarjan(i);
        forn(i, n) if (comp[i] == comp[neg(i)]) return false;
        return true;
    }
};
