struct Max { // op = max, neutro = -INF
    int x; Max(int _x=-INF) { x = _x; }
    Max operator+(const Max &o) { return x > o.x ? *this : o; }
    bool operator!=(const Max &o) { return x != o.x; }
};
template<class T>
struct RMQ { // ops O(lg n), [0, n)
    vector<T> t; int n;
	T& operator[](int p) { return t[p+n]; }
	RMQ(int sz) { n = 1 << (32-__builtin_clz(sz)), t.resize(2*n); }
    void build() { dforn(i, n) t[i] = t[2*i] + t[2*i+1]; }
	T get(int i, int j) { return get(i, j, 1, 0, n); }
	T get(int i, int j, int x, int a, int b) {
		if (j <= a || i >= b) return T();
		if (i <= a && b <= j) return t[x];
		int c = (a + b) / 2;
		return get(i, j, 2*x, a, c) + get(i, j, 2*x+1, c, b);
	}
	void set(int p, T v) {
		for (p += n; p && t[p] != v;)
			t[p] = v, p /= 2, v = t[p*2] + t[p*2+1];
	}
};
// Use: RMQ<Max> rmq(n); forn(i, n) cin >> rmq[i].x; rmq.build();

