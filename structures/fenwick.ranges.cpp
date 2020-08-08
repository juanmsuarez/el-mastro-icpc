// Point update, range query:
template<class T>
struct BIT { // ops O(lg n), [0, n)
    int n, h; vector<T> d;
    BIT(int sz) { n = sz, d.resize(n+1), h = 1 << int(log2(n)); }
    void add(int i, T x) { for (++i; i <= n; i += i&-i) d[i] += x; }
    T sum(int i) { T r = 0; for (; i; i -= i&-i) r += d[i]; return r; }
    T sum(int l, int r) { return sum(r) - sum(l); }
    int lower_bound(T v) {
        int x = 0;
        for (int p = h; p; p >>= 1) 
            if ((x|p) <= n && d[x|p] < v) v -= d[x |= p];
        return x; 
    }
};

// Range update, point query:
template<class T>
struct BIT { // ops O(lg n), [0, n)
    vector<T> d; int n; BIT(int sz) { n=sz, d.resize(n+1); }
    void add(int l, int r, T x) { _add(l, x), _add(r, -x); }
    void _add(int i, T x) { for (++i; i <= n; i += i&-i) d[i] += x; }
    T sum(int i) { T r = 0; for (++i; i; i -= i&-i) r += d[i]; return r; }
};

// Range update, range query:
template<class T>
struct BIT { // ops O(lg n), [0, n)
    int n; vector<T> m, a;
    BIT(int sz) { n = sz, m.resize(n+1), a.resize(n+1); }
    void add(int l, int r, T x) { 
        _add(l, x, -x*l), _add(r-1, -x, x*r); 
    }
    void _add(int i, T x, T y) { 
        for (++i; i <= n; i += i&-i) m[i] += x, a[i] += y; 
    }
    T sum(int i) {
        T x = 0, y = 0, s = i;
        for (; i; i -= i&-i) x += m[i], y += a[i];
        return x*s + y;
    }
    T sum(int l, int r) { return sum(r) - sum(l); }
};
