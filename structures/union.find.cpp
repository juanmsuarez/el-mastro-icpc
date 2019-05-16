struct UF { // Operations take O(log*(n))
    vi p,s;
    UF(int n){ p.resize(n), iota(all(p), 0), s.assign(n, 1); }
    int find(int i){
	    while (p[i] != i) p[i] = p[p[i]], i = p[i];
	    return i;
    }
    bool con(int x, int y){ return find(x) == find(y); }
    bool join(int x, int y){
    	x = find(x), y = find(y);
        if (con(x, y)) return false;

    	if (s[x] < s[y]) p[x] = y, s[y] += s[x];
    	else p[y] = x, s[x] += s[y];
        return true;
    }
};

