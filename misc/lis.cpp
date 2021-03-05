const int INF = 2e9;
int lis(const vi &a) { // O(n lg n)
    int r = 0;
    vi v(si(a) + 1, INF); v[0] = -INF;
    for (int x : a) {
        int j = int(upper_bound(all(v), x) - begin(v));
        if (v[j-1] < x) v[j] = x, r = max(r, j);
    }
    return r;
}
--------------------------------------------------------------------
const int INF = 2e9;
vi lis(const vi &a) { // O(n lg n)
    int n = si(a), r = 0;
    vi v(n+1, INF), id(n+1), p(n); v[0] = -INF;
    forn(i, n) {
        int x = a[i], j = int(upper_bound(all(v), x) - begin(v));
        if (v[j-1] < x) v[j] = x, r = max(r, j), id[j] = i, p[i] = id[j-1];
    }
    vi path(r); int c = id[r];
    dforn(i, r) path[i] = a[c], c = p[c];
    return path;
}
