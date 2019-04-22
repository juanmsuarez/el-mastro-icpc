struct DSU { // Operations take O(log*(n))
    vi p,s;
    DSU(int n){ p.resize(n), iota(all(p),0), s.assign(n,1); }
    int root(int i){
	    while(p[i] != i) p[i] = p[p[i]], i = p[i];
	    return i;
    }
    bool find(int x, int y){ return root(x) == root(y); }
    void join(int x, int y){
    	x = root(x), y = root(y);
    	if(s[x] < s[y]) p[x] = y, s[y] += s[x];
    	else p[y] = x, s[x] += s[y];
    }
};

