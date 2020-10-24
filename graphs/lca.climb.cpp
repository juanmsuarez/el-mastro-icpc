#define lg(x) (31-__builtin_clz(x))
struct LCA {
    vector<vi> a; vi lvl; // a[i][k] is the 2^k ancestor of i
    void dfs(int u=0, int p=-1, int l=0) {
        a[u][0] = p, lvl[u] = l; 
        for (int v : g[u]) if (v != p) dfs(v, u, l+1);
    }
    LCA(int n) : a(n, vi(lg(n)+1)), lvl(n) {
        dfs(); forn(k, lg(n)) forn(i, n) a[i][k+1] = a[i][k] == -1 ? -1 : a[a[i][k]][k]; 
    }
    int climb(int x, int d) {
        for (int i = lg(lvl[x]); d && i >= 0; i--) 
            if ((1 << i) <= d) x = a[x][i], d -= 1 << i;
        return x; 
    }
    int lca(int x, int y) { // O(lg n)
        if (lvl[x] < lvl[y]) swap(x, y);
        if (lvl[x] != lvl[y]) x = climb(x, lvl[x] - lvl[y]);
        if (x != y) { 
            for (int i = lg(lvl[x]); i >= 0; i--) 
                if (a[x][i] != a[y][i]) x = a[x][i], y = a[y][i]; 
            x = a[x][0]; 
        }
        return x;
    }
    int dist(int x, int y) { return lvl[x] + lvl[y] - 2 * lvl[lca(x, y)]; }
};
