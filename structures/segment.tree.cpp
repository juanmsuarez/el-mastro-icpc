// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
typedef int node; // Tipo de los nodos
#define MAXN 100000
#define operacion(x, y) min(x, y)
const int neutro = INT_MAX;
struct RMQ {
	int sz;
	node t[4*MAXN];
	node &operator [](int p){ return t[sz + p]; }
	void init(int n){ // O(n)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
    void updall(){//O(n)
        dforsn(i,0,sz) t[i] = operacion(t[2*i], t[2*i + 1]);
    }
	node get(int i, int j){ return get(i, j, 1, 0, sz); }
	node get(int i, int j, int n, int a, int b){ // O(lg n)
		if(j <= a || i >= b) return neutro;
		if(i <= a && b <= j) return t[n];
		int c = (a + b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n + 1, c, b));
	}
	void set(int p, node val){ // O(lg n)
		for(p += sz; p > 0 && t[p] != val;){
			t[p] = val, p /= 2;
			val = operacion(t[p*2], t[p*2 + 1]);
		}
	}
} rmq;
// Uso:
cin >> n; rmq.init(n); forn(i, n) cin >> rmq[i]; rmq.updall();
