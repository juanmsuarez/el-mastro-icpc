template<class T>
struct BIT { // ops O(lg n), [0, n)
    int n; vector<T> d; BIT() {}
    BIT(int sz) { n = sz, d.resize(n+1); }
    void add(int i, T x) { for (++i; i <= n; i += i&-i) d[i] += x; }
    T sum(int i) { T r = 0; for (; i; i -= i&-i) r += d[i]; return r; }
    T sum(int l, int r) { return sum(r) - sum(l); }
};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct BasicHashing {
    int n, mod, base; vi a, pot; BIT<ll> rmq;
    BasicHashing() {
        mod = uniform_int_distribution<>(int(1e9), int(15e8))(rnd);
        bool prime;
        do {
            mod++, prime = true;
            for (ll d = 2; prime && d*d <= mod; ++d) 
                if (mod % d == 0) prime = false;
        } while (!prime);
        base = uniform_int_distribution<>(256, mod-1)(rnd);
    }
    void process(const string &s) {
        n = si(s), a = vi(n), pot = vi(n), pot[0] = 1; 
        forn(i, n-1) pot[i+1] = int(pot[i] * ll(base) % mod);
        forn(i, n) a[i] = int(s[i] * ll(pot[i]) % mod);
        rmq = BIT<ll>(n); forn(i, n) rmq.add(i, a[i]);
    }
    int hash(int i, int j) { // [ )
        return int(rmq.sum(i, j) * ll(pot[n-j]) % mod);
    }
    void set(int i, int x) {
        int old = a[i];
        a[i] = int(x * ll(pot[i]) % mod);
        rmq.add(i, -old + a[i]);
    }
};
struct Hashing {
    BasicHashing h1, h2;
    void process(const string &s) { h1.process(s), h2.process(s); }
    pii hash(int i, int j) { return {h1.hash(i, j), h2.hash(i, j)}; } 
    void set(int i, int x) { h1.set(i, x), h2.set(i, x); } 
};
