mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct BasicHashing {
    int mod, base; vi h, pot;
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
        int n = si(s); h = vi(n+1), pot = vi(n+1);
        h[0] = 0; forn(i, n) h[i+1] = int((h[i] * ll(base) + s[i]) % mod);
        pot[0] = 1; forn(i, n) pot[i+1] = int(pot[i] * ll(base) % mod);
    }
    int hash(int i, int j) { // [ )
        int res = int(h[j] - ll(h[i]) * pot[j-i] % mod);
        return res < 0 ? res + mod : res;
    }
    int hash(const string &s) {
        int res = 0;
        for (char c : s) res = int((res * ll(base) + c) % mod);
        return res;
    }
    int append(int a, int b, int szb) { 
        return int((ll(a) * pot[szb] + b) % mod); 
    }
};
struct Hashing {
    BasicHashing h1, h2;
    void process(const string &s) { h1.process(s), h2.process(s); }
    pii hash(int i, int j) { return {h1.hash(i, j), h2.hash(i, j)}; } 
    pii hash(const string &s) { return {h1.hash(s), h2.hash(s)}; }
    pii append(pii &a, pii &b, int szb) {
        return {h1.append(a.fst, b.fst, szb), h2.append(a.snd, b.snd, szb)}; 
    }
};
