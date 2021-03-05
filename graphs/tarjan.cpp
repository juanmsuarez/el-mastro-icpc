// idx[i] = index assigned in the dfs
// low[i] = lowest index (closer from the root) reachable from i
struct SCC {
    vector<vi> g;
    stack<int> q;
    vi low, idx, comp;
    int n, id, comps, x;

    SCC(int _n) {
        n = _n, g.resize(n), id = 0, comps = 0;
        low = vi(n), idx = vi(n, -1), comp = vi(n, -1);
    }

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
            comps++;
        }
    }

    void run() { forn(i, n) if (idx[i] == -1) tarjan(i); } 
};
