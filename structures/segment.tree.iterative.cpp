#define op(a,b) max(a,b)
#define ne -2e9
template <class T>
struct RMQ { // ops O(lg n), [0, n)
    vector<T> t; int n;
    T& operator[](int p){ return t[p+n]; }
    RMQ(int sz){ n = sz, t.assign(2*n, ne); }
    void build(){ dforsn(i,1,n) t[i] = op(t[i<<1], t[i<<1|1]); }
    void set(int p, T v){ 
        for(t[p += n] = v; p >>= 1;) t[p] = op(t[p<<1], t[p<<1|1]); 
    }
    T get(int l, int r){
        T a=ne, b=ne;
        for(l+=n, r+=n; l < r; l>>=1, r>>=1){
            if(l&1) a = op(a, t[l++]);
            if(r&1) b = op(t[--r], b);
        }
        return op(a,b);
    }
};
