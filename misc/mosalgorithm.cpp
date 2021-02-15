// ONLY QUERIES
struct Mo {
    static const int S = 500; // S = sqrt(N)
    struct Query { // [l, r)
        int l, r, id;
        bool operator<(const Query &q) {
            if (l/S != q.l/S) return l < q.l;
            return l/S & 1 ? r < q.r : r > q.r;
        }
    }; 

    vector<Query> qs;
    int cl = 0, cr = 0, cq = 0, res = 0; vi ans;

    Mo(int q) : qs(q), ans(q) {}

    void addQuery(int l, int r) { qs[cq] = {l, r, cq++}; }
    void run() { // O((n + q) * sqrt(n) * (add() + del()))
        sort(all(qs));
        for (auto &q : qs) {
            while (cl > q.l) add(--cl);
            while (cr < q.r) add(cr++);
            while (cl < q.l) del(cl++);
            while (cr > q.r) del(--cr);
            ans[q.id] = res;
        }
    }
};

// QUERIES AND UPDATES
struct Mo {
    static const int S = 2700; // S = cbrt(2 * N * N)
    struct Query { // [l, r)
        int l, r, id, t;
        bool operator<(const Query &o) {
            if (l/S != o.l/S) return l < o.l;
            if (r/S != o.r/S) return r < o.r;
            return t < o.t;
        }
    }; 
    struct Update { int x, v; }; 

    vector<Query> qs; vector<Update> us;
    int cl = 0, cr = 0, ct = 0, res = 0; vi ans;

    void addQuery(int l, int r) { qs.pb(l, r, si(qs), si(us)); }
    void addUpdate(int x, int v) { us.pb(x, v); }
    // O(q*s * (add() + del()) + n * del() + n^2/s * add() + q*(n/s)^2 * (upd() + undo()))
    void run() { // si n = q y ops. ctes. O(n^(5/3))
        ans.resize(si(qs));
        sort(all(qs));
        for (auto &q : qs) {
            while (cl > q.l) add(--cl);
            while (cr < q.r) add(cr++);
            while (cl < q.l) del(cl++);
            while (cr > q.r) del(--cr);
            while (ct < q.t) upd(ct++);
            while (ct > q.t) undo(--ct);
            ans[q.id] = res;
        }
    }

    void upd(int u) { // IMPLEMENT! ex. op.: a[x] = v
        bool in = cl <= us[u].x && us[u].x < cr;
        if (in) del(us[u].x);
        swap(a[us[u].x], us[u].v);         
        if (in) add(us[u].x);
    }

    void undo(int u) { // IMPLEMENT! could be different to upd(), ex. op.: a[x] = v
        bool in = cl <= us[u].x && us[u].x < cr;
        if (in) del(us[u].x);
        swap(a[us[u].x], us[u].v);
        if (in) add(us[u].x);
    }
};
