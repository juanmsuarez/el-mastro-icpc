struct Max { // op = max, neutral = -INF
    int x; Max(int _x = -INF) { x = _x; }
    Max operator+(const Max &o) { return x > o.x ? *this : o; }
};
template<class T>
struct RMQ { // ops O(lg n), [0, n)
    vector<T> t; int n;
    T& operator[](int p) { return t[p + n]; }
    RMQ(int sz) { n = sz, t.resize(2*n); }
    void build() { dforsn(i, 1, n) t[i] = t[2*i] + t[2*i+1]; }
    void set(int p, T v) {  
        for (t[p += n] = v; p /= 2;) t[p] = t[2*p] + t[2*p+1]; 
    }
    T get(int l, int r) {
        T a, b; 
        for (l+=n, r+=n; l < r; l/=2, r/=2){
            if (l & 1) a = a + t[l++];
            if (r & 1) b = t[--r] + b;
        }
        return a + b;
    }
};
// Use: RMQ<Max> rmq(n); forn(i, n) { int x; cin >> x; rmq[i] = x; } rmq.build();
