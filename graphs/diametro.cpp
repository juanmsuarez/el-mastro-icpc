int n;
vi adj[N];

pii farthest(int u, int p = -1) {
    pii ans = {-1, u};

    for (int v : adj[u])
        if (v != p)
            ans = max(ans, farthest(v, u));

    ans.fst++;
    return ans;
}

int diam(int r) {
    return farthest(farthest(r).snd).fst;
}

bool path(int s, int e, vi &p, int pre = -1) {
    p.pb(s); 
    if (s == e) return true;

    for (int v : adj[s])
        if (v != pre && path(v, e, p, s))
            return true;

    p.pop_back();
    return false;
}

int center(int r) {
    int s = farthest(r).snd, e = farthest(s).snd;
    vi p; path(s, e, p);
    return p[si(p)/2];
}
