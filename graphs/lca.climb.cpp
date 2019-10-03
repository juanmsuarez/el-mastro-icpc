#define lg(x) (31-__builtin_clz(x))
struct LCA {
    static const int L = 20;
    int n, a[N][L], lvl[N]; // a[i][k] is the 2^k ancestor of i
 
    void dfs(int u=0, int p=-1, int d=0){
        a[u][0] = p, lvl[u] = d; 
        for(int v : tree[u]) if(v != p) dfs(v,u,d+1);
    }
 
    void init(int m){
        n = m; dfs(); forn(k, L-1) forn(i,n) if(a[i][k] != -1) a[i][k+1] = a[a[i][k]][k]; 
    }
 
    int climb(int x, int d){
        if(d) for(int i = lg(lvl[x]); d && i >= 0; i--) 
            if(1 << i <= d) x = a[x][i], d -= 1 << i;
        return x; 
    }
 
    int lca(int x, int y){ // O(lgn)
        if(lvl[x] < lvl[y]) swap(x,y);
        x = climb(x, lvl[x] - lvl[y]);
        if(x != y){ 
            for(int i = lg(lvl[x]); i >= 0; i--) 
                if(a[x][i] != a[y][i]) x = a[x][i], y = a[y][i]; 
            x = a[x][0]; 
        }
        return x;
    }
 
    int dist(int x, int y){ return lvl[x] + lvl[y] - 2*lvl[lca(x,y)]; }
} lca;
