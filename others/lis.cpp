int lis(const vi &a) { // O(n lg n)
    int n = si(a), INF = 2e9, r = 0;
    vi v(n+1,INF); v[0] = -INF;
    forn(i,n){
        int j = int(upper_bound(all(v), a[i]) - v.begin());
        if(v[j-1] < a[i] && a[i] < v[j]) v[j] = a[i], r = max(r,j);
    }
    return r;
}

--------------------------------------------------------------------

vi path;
int lis(const vi &a) { // O(n lg n)
    int n = si(a), INF = 2e9, r = 0;
    vi v(n+1,INF),id(n+1),p(n); 
    v[0] = -INF;

    forn(i,n){
        int j = int(upper_bound(all(v), a[i]) - v.begin());
        if(v[j-1] < a[i] && a[i] < v[j]) 
            v[j] = a[i], r = max(r,j), id[j] = i, p[i] = id[j-1];
    }

    path = vi(r); int c = id[r];
    forn(i,r) path[r-i-1] = a[c], c = p[c];
    return r;
}
