// TODO: Las funciones pueden pasarse a traves de template. Quedara mejor sacar el struct tipo y reemplazar por todo en template?

const int N = 1e5, INF = 1e9;

struct TipoAlt {
    int val;

    TipoAlt(int _val=0) : val(_val) {}

    static int neutro() { return 0; } // neutro alteracion
    TipoAlt operator * (const int sz) {
        return TipoAlt(val*sz);
    }
    TipoAlt& operator += (const TipoAlt &o) { val += o.val; return *this; } // propaga alteracion, ejemplo suma
};

struct TipoNodo {
    int val;

    TipoNodo(int _val=0) : val(_val) {}

    static int neutro() { return INF; } // neutro nodo
    TipoNodo operator + (const TipoNodo &o) const { return min(val, o.val); } // operacion nodo, ejemplo min
    TipoNodo& operator += (const TipoAlt &o) { val += o.val; return *this; } // aplica alteracion, ejemplo suma
};

// Dado un arreglo y una operacion asociativa con neutro:
// get(i, j) opera sobre el rango [i, j).
template <int N, class TNodo, class TAlt>
struct RMQ {
	int sz;
	TNodo t[4*N];
	TAlt dirty[4*N];
	TNodo &operator [](int p){ return t[sz + p]; }
    void init(int n) { // O(n lg n)
        sz = 1 << (32 - __builtin_clz(n));
        forn(i, 2*sz) {
            t[i] = TNodo::neutro();
            dirty[i] = TAlt::neutro();
        }
    }
	void push(int n, int a, int b){ // Propaga el dirty a sus hijos
		if (dirty[n].val != TAlt::neutro().val){
			t[n] += dirty[n]*(b - a); // Altera el nodo 
			if (n < sz){
				dirty[2*n] += dirty[n];
				dirty[2*n + 1] += dirty[n];
			}
			dirty[n] = TAlt::neutro();
		}
	}
	TNodo get(int i, int j, int n, int a, int b){ // O(lg n)
		if (j <= a || i >= b) return TNodo::neutro();
		push(n, a, b); // Corrige el valor antes de usarlo
		if (i <= a && b <= j) return t[n];
		int c = (a + b)/2;
		return get(i, j, 2*n, a, c) + get(i, j, 2*n + 1, c, b);
	}
	TNodo get(int i, int j){ return get(i, j, 1, 0, sz); }
	// Altera los valores en [i, j) con una alteracion de val
	void modify(TAlt val, int i, int j, int n, int a, int b){ // O(lg n)
		push(n, a, b);
		if (j <= a || i >= b) return;
		if (i <= a && b <= j) {
			dirty[n] += val;
			push(n, a, b);
			return;
		}
		int c = (a + b)/2;
		modify(val, i, j, 2*n, a, c); modify(val, i, j, 2*n + 1, c, b);
		t[n] = t[2*n] + t[2*n + 1];
	}
	void modify(TAlt val, int i, int j){ modify(val, i, j, 1, 0, sz); }
};

RMQ<N, TipoNodo, TipoAlt> rmq;

