map<ll,int> fact(int x) { // O(lg x), x <= N
    map<ll,int> f;
    while (x > 1) f[lp[x]]++, x /= lp[x];
    return f;
}

map<ll,int> fact(ll x) { // O(sqrt x), x <= N*N
    map<ll,int> f;
    for (int p : P) {
        if (ll(p)*p > x) break;
        while (x % p == 0) f[p]++, x /= p;
    }
    if (x > 1) f[x]++;
    return f;
}
