// Para 2D: tratar cada columna como un Fenwick Tree, 
// agregando un for anidado en cada operacion.
// Trucos: 
// - La operacion puede no tener inverso ;)
// - Podemos usar unordered_map si tenemos que trabajar con numeros grandes

// Point update, range query:
template<class T>
struct Fenwick { // ops O(lg n), [0, n)
    int n, h; vector<T> d;
    Fenwick(int sz) { n = sz, d.resize(n+1), h = 1 << int(log2(n)); }
    void upd(int i, T x) { for (++i; i <= n; i += i&-i) d[i] += x; }
    T get(int i) { T r = 0; for (; i; i -= i&-i) r += d[i]; return r; }
    T get(int l, int r) { return get(r) - get(l); }
    int lower_bound(T v) {
        int x = 0;
        for (int p = h; p; p >>= 1) 
            if ((x|p) <= n && d[x|p] < v) v -= d[x |= p];
        return x; 
    }
};

// Range update, point query:
template<class T>
struct Fenwick { // ops O(lg n), [0, n)
    vector<T> d; int n; Fenwick(int sz) { n=sz, d.resize(n+1); }
    void upd(int l, int r, T x) { _upd(l, x), _upd(r, -x); }
    void _upd(int i, T x) { for (++i; i <= n; i += i&-i) d[i] += x; }
    T get(int i) { T r = 0; for (++i; i; i -= i&-i) r += d[i]; return r; }
};

// Range update, range query:
template<class T>
struct Fenwick { // ops O(lg n), [0, n)
    int n; vector<T> m, a;
    Fenwick(int sz) { n = sz, m.resize(n+1), a.resize(n+1); }
    void upd(int l, int r, T x) { 
        _upd(l, x, -x*l), _upd(r-1, -x, x*r); 
    }
    void _upd(int i, T x, T y) { 
        for (++i; i <= n; i += i&-i) m[i] += x, a[i] += y; 
    }
    T get(int i) {
        T x = 0, y = 0, s = i;
        for (; i; i -= i&-i) x += m[i], y += a[i];
        return x*s + y;
    }
    T get(int l, int r) { return get(r) - get(l); }
};
