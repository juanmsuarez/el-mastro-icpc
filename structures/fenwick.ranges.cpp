// Point update, range query:
typedef ll T;
struct BIT { // ops O(lg n), [0, N)
    T d[N+1];
    void add(int i, T x) { for (++i; i <= N; i += i&-i) d[i] += x; }
    T sum(int i) { T r = 0; for (; i; i -= i&-i) r += d[i]; return r; }
    T sum(int l, int r) { return sum(r) - sum(l); }
    int lower_bound(T v, int n) { // n = first number out of range
        int x = 0;
        for (int p = N; p; p >>= 1) 
            if ((x|p) <= n && d[x|p] < v) 
                v -= d[x |= p];
        return x; 
    }
} rmq;

// Range update, point query:
template<class T>
struct BIT { // ops O(lg n), [0, n)
    vector<T> d; int n; BIT(int sz) { n=sz, d.resize(n+1); }
    void add(int l, int r, T x) { _add(l, x), _add(r, -x); }
    void _add(int i, T x) { for (++i; i <= n; i += i&-i) d[i] += x; }
    T get(int i) { T r = 0; for (++i; i; i -= i&-i) r += d[i]; return r; }
};

// Range update, range query:
typedef ll T;
struct BIT { // ops O(lg n), [0, N)
    T m[N+1], a[N+1];
    void add(int l, int r, T x) { 
        _add(l, x, -x*l), _add(r-1, -x, x*r); 
    }
    void _add(int i, T x, T y) { 
        for (++i; i <= N; i += i&-i) m[i] += x, a[i] += y; 
    }
    T sum(int i){
        T x = 0, y = 0, s = i;
        for (; i; i -= i&-i) x += m[i], y += a[i];
        return x*s + y;
    }
    T sum(int l, int r) { return sum(r) - sum(l); }
} rmq;
