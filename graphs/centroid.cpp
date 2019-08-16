vi tree[N];
 
struct Centroid {
    int n, sz[N], parent[N]; bool used[N];
 
    int size(int u, int p=-1){
        sz[u] = 1; 
        for(int v : tree[u]) 
            if(v != p && !used[v]) sz[u] += size(v,u);
        return sz[u];
    }
    
    void build(int u=0, int p=-1, int s=-1){
        if(s == -1) s = size(u);
        for(int v : tree[u]) if(!used[v] && sz[v] > s/2)
            { sz[u] = 0; build(v,p,s); return; }
        used[u] = true, parent[u] = p; 
        for(int v : tree[u]) if(!used[v]) build(v,u,-1);
    }
 
    void init(int _n){ n = _n; forn(i,n) used[i] = false; build(); } // O(nlgn)
 
} centroid;
