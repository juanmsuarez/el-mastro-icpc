const int N = 1e6;
vi C(N+1), D[N+1]; // D[x] contains all the divisors of x

void generateDivisors() { // O(n lg n) because of the harmonic series
    forsn(i, 1, N+1) for (int j = i; j <= N; j += i) C[j]++;
    forsn(i, 1, N+1) D[i] = vi(C[i]), C[i] = 0;
    forsn(i, 1, N+1) for (int j = i; j <= N; j += i) D[j][C[j]++] = i;
}

typedef vector<ll> vll;

vll divisors(ll x) { // O(sqrt x)
    vll r;
    for (ll i = 1; i*i <= x; i++) {
        ll d = x/i;
        if (d*i == x) {
            r.pb(i);
            if (d != i) r.pb(d);
        }
    }
    return r;
}

vll divisors(const map<ll,int> &f) { // O(num of divs)
    vll d = {1}; // divs are unordered
    for (auto &i : f) {
        ll b = 1, n = si(d);
        forn(_, i.snd) {
            b *= i.fst;
            forn(j, n) d.pb(b * d[j]);
        }
    }
    return d;
} 

ll sumDivisors(ll x) { // O(lg x)
    ll r = 1;
    map<ll,int> f = fact(x);
    for (auto &i : f) {
	    ll pow = 1, s = 0;  
	    forn(j, i.snd + 1) 
            s += pow, pow *= i.fst;
	    r *= s;
    } 
    return r;
}
