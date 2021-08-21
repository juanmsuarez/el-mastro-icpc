struct Lazy {
    static const int C = 0; // Neutral for sum: 0
    int val; Lazy(int v=C) : val(v) {}
    bool dirty() { return val != C; }
    void clear() { val = C; }
    void update(const Lazy &o) { val += o.val; } // Update: sum
};
struct Node {
    int val; Node(int v=INF) : val(v) {} // Neutral for min: INF
    Node operator+(const Node &o) { return min(val, o.val); } // Query: min
    void update(const Lazy &o, int sz) { val += o.val; } // Update: sum
};
template <class T, class D>
struct RMQ { // ops O(lg n), [0, n)
    vector<T> t; vector<D> d; int n;
	T& operator[](int p){ return t[p+n]; }
	RMQ(int sz) { 
        n = 1; while (n < sz) n *= 2;
        t.resize(2*n), d.resize(2*n); 
    }
    void build() { dforsn(i, 1, n) t[i] = t[2*i] + t[2*i + 1]; }
	void push(int x, int sz) {
		if (d[x].dirty()){
            t[x].update(d[x], sz);
			if (sz > 1) d[2*x].update(d[x]), d[2*x + 1].update(d[x]);
		    d[x].clear();
		}
	}
	T get(int i, int j) { return get(i, j, 1, 0, n); }
	T get(int i, int j, int x, int a, int b) {
		if (j <= a || i >= b) return T();
		push(x, b-a);
		if (i <= a && b <= j) return t[x];
		int c = (a + b) / 2;
        return get(i, j, 2*x, a, c) + get(i, j, 2*x + 1, c, b);
	}
	void update(int i, int j, const D &v) { update(i, j, v, 1, 0, n); }
	void update(int i, int j, const D &v, int x, int a, int b) {
		push(x, b-a);
		if (j <= a || i >= b) return;
		if (i <= a && b <= j) { d[x].update(v), push(x, b-a); return; }
		int c = (a + b) / 2;
		update(i, j, v, 2*x, a, c), update(i, j, v, 2*x + 1, c, b);
        t[x] = t[2*x] + t[2*x + 1];
	}
};
// Use: RMQ<Node, Lazy> rmq(n); forn(i, n) cin >> rmq[i].val; rmq.build();
