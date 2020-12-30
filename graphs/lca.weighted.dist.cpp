#define lg(x) (31-__builtin_clz(x))
struct LCA {
    vector<vi> a; vi lvl; // a[i][k] = 2^k ancestor of i
    vector<vector<ll>> d; // d[i][k] = distance from i to a[i][k]
    void dfs(int u=0, int p=-1, int l=0, int e=0) {
        a[u][0] = p, lvl[u] = l, d[u][0] = e;
        for (auto [v, w] : g[u]) if (v != p) dfs(v, u, l+1, w);
    }
    LCA(int n) : a(n, vi(lg(n)+1)), lvl(n), d(n, vector<ll>(lg(n)+1)) {
        dfs(); forn(k, lg(n)) forn(i, n) {
            if (a[i][k] == -1) a[i][k+1] = -1;
            else a[i][k+1] = a[a[i][k]][k], d[i][k+1] = d[i][k] + d[a[i][k]][k];
        }
    }
    pair<int, ll> climb(int x, int j) {
        ll s = 0;
        for (int i = lg(lvl[x]); j && i >= 0; i--) 
            if ((1 << i) <= j) s += d[x][i], x = a[x][i], j -= 1 << i;
        return {x, s}; // {j-th ancestor of x, distance}
    }
    pair<int, ll> lca(int x, int y) { // O(lg n)
        ll s = 0;
        if (lvl[x] < lvl[y]) swap(x, y);
        auto [nx, dx] = climb(x, lvl[x] - lvl[y]);
        x = nx, s += dx;
        if (x != y) { 
            for (int i = lg(lvl[x]); i >= 0; i--) if (a[x][i] != a[y][i])
                s += d[x][i], x = a[x][i], s += d[y][i], y = a[y][i];  
            s += d[x][0], s += d[y][0], x = a[x][0]; 
        }
        return {x, s}; // {lca, distance}
    }
    ll dist(int x, int y) { return lca(x, y).snd; }
};
