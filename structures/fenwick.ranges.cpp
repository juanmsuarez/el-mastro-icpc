// Point update, range query:
typedef ll T;
struct BIT { // ops O(lg n), [0, N-1]
    T d[N+1];
    void add(int i, T x){ for(++i; i <= N; i += i&-i) d[i] += x; }
    T sum(int i){ T r = 0; for(++i; i; i -= i&-i) r += d[i]; return r; }
    T sum(int l, int r){ return sum(r)-sum(l-1); }
} rmq;

// Range update, point query:
typedef ll T;
struct BIT { // ops O(lg n), [0, N-1]
    T d[N+1];
    void add(int l, int r, T x){ _add(l,x); _add(r+1,-x); }
    void _add(int i, T x){ for(++i; i <= N; i += i&-i) d[i] += x; }
    T sum(int i){ T r = 0; for(++i; i; i -= i&-i) r += d[i]; return r; }
} rmq;

// Range update, range query:
typedef ll T;
struct BIT { // ops O(lg n), [0, N-1]
    T m[N+1],a[N+1];
    void add(int l, int r, T x){ 
        l++,r++, _add(l,x,-x*(l-1)), _add(r+1,-x,x*r); 
    }
    void _add(int i, T x, T y){ 
        for(; i <= N; i += i&-i) m[i] += x, a[i] += y; 
    }
    T sum(int i){
        T x=0, y=0, s=++i;
        for(; i; i -= i&-i) x += m[i], y += a[i];
        return x*s + y;
    }
    T sum(int l, int r){ return sum(r)-sum(l-1); }
} rmq;
