template<class T, int none>
struct assignment { // ops O(lg n), [0, n)
    vector<T> t; int n, h;
	T& operator[](int p) { return t[p+n]; }
	assignment(int sz) { 
        h = 32-__builtin_clz(sz);
        n = 1 << h, t.assign(2*n, none); 
    }
	void set(int i, int j, T v) { set(i, j, v, 1, 0, n); }
	void set(int i, int j, T v, int x, int a, int b) {
		if (j <= a || i >= b) return;
		if (i <= a && b <= j) { t[x] = v; return; }
        if (t[x] != none) 
            t[2*x] = t[2*x+1] = t[x], t[x] = none;
		int c = (a + b) / 2;
		set(i, j, v, 2*x, a, c), set(i, j, v, 2*x+1, c, b);
	}
    T get(int p) {
        p += n; int i = h;
        while (i && t[p >> i] == none) i--;
        return t[p >> i];
	}
};
