struct rmax { // op = max, neutro = -INF
    int x; rmax(int _x=-INF) { x = _x; }
    rmax operator+(const rmax &o) { return x > o.x ? *this : o; }
};
template<class T>
struct RMQ { // ops O(lg n), [0, n)
    vector<T> t; int n;
    T& operator[](int p){ return t[p+n]; }
    RMQ(int sz){ n = sz, t.resize(2*n); }
    void build(){ dforsn(i,1,n) t[i] = t[i<<1] + t[i<<1|1]; }
    void set(int p, T v){ 
        for(t[p += n] = v; p >>= 1;) t[p] = t[p<<1] + t[p<<1|1]; 
    }
    T get(int l, int r){
        T a,b; 
        for(l+=n, r+=n; l < r; l>>=1, r>>=1){
            if(l&1) a = a + t[l++];
            if(r&1) b = t[--r] + b;
        }
        return a+b;
    }
};
// Use: RMQ<rmax> rmq(n); forn(i, n) { int x; cin >> x; rmq[i].x = x; } rmq.build();
