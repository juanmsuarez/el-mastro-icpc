struct mi {
	static const int M = 1e9+7;
	int v;
	mi(int _v = 0):v(_v) {} // aca se podria aplicar mod
	mi operator +(mi o){ return v + o.v >= M ? v + o.v - M : v + o.v; }
	mi operator -(mi o){ return v - o.v < 0 ? v - o.v + M : v - o.v; }
	mi operator *(mi o){ return (int)((ll)v*o.v%M); }
	mi operator ^(int e){
        if(!e) return 1;
        mi q = *this^(e/2); q = q*q;
        return (e & 1 ? q*v : q);
    }
    bool operator == (const mi &o) const { return v == o.v; }
    bool operator != (const mi &o) const { return v != o.v; }
};
mi inv(mi m) { return m^(m.M-2); } // solo si M es primo
