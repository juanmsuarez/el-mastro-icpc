// Both functions require sieve to work (factorize.cpp)
using mli = map<ll, int>;
mli fact(int x) { // O(lg x), x <= N
    mli f;
    while (x > 1) f[lp[x]]++, x /= lp[x];
    return f;
}
mli fact(ll x) { // O(sqrt x), x <= N*N
    mli f;
    for (int p : P) {
        if (ll(p)*p > x) break;
        while (x % p == 0) f[p]++, x /= p;
    }
    if (x > 1) f[x]++;
    return f;
}
