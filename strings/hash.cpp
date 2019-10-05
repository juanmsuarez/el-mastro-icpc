mt19937 rng;
struct basicHashing {
    int mod,mul; vi h,pot;

    bool prime(int n) { 
        for (int d = 2; d*d <= n; d++) if (n%d == 0) return false;
        return true;
    }

    void randomize() {
        rng.seed(chrono::steady_clock::now().time_since_epoch().count());
        mod = uniform_int_distribution<>(0, (int) 5e8)(rng) + int(1e9);
        while (!prime(mod)) mod++;
        mul = uniform_int_distribution<>(2,mod-2)(rng);
    }
    basicHashing() { randomize(); }

    void process(const string &s) {
        int n = si(s); h = vi(n+1), pot = vi(n+1);
        h[0] = 0; forn(i,n) h[i+1] = int(( ll(h[i])*mul + s[i]) % mod);
        pot[0] = 1; forn(i,n) pot[i+1] = int( ll(pot[i]) * mul % mod);
    }

    int hash(int i, int j) { // [ )
        int res = int(h[j] - ll(h[i])*pot[j-i] % mod);
        if (res < 0) res += mod;
        return res;
    }
    int hash(const string &s) {
        int res = 0;
        for (char c : s) res = int(( ll(res)*mul + c) % mod);
        return res;
    }
    int append(int a, int b, int szb){ 
        return int(( ll(a)*pot[szb] + b) % mod); 
    }
};

struct hashing {
    basicHashing h1,h2;
    void process(const string &s){ h1.process(s), h2.process(s); }
    pii hash(int i, int j){ return {h1.hash(i,j), h2.hash(i,j)}; } 
    pii hash(const string &s) { return {h1.hash(s), h2.hash(s)}; }
    pii append(pii &a, pii &b, int szb){
        return { h1.append(a.fst,b.fst,szb), h2.append(a.snd,b.snd,szb) }; 
    }
};
