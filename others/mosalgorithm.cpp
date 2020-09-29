struct Mo {
    static const int SQ = 500;
    struct Query { // [l, r)
        int l, r, id;
        bool operator<(const Query &q) {
            if (l/SQ != q.l/SQ) return l < q.l;
            return l/SQ & 1 ? r < q.r : r > q.r;
        }
    }; vector<Query> qs;
    int l = 0, r = 0, p = 0, res = 0; vi ans;
    Mo(int q) : qs(q), ans(q) {}
    void addQuery(int x, int y) { qs[p] = {x, y, p++}; }
    void run() { // O((n + q) * sqrt(n) * (add() + del()))
        sort(all(qs));
        for (auto &q : qs) {
            while (l > q.l) add(--l);
            while (r < q.r) add(r++);
            while (l < q.l) del(l++);
            while (r > q.r) del(--r);
            ans[q.id] = res;
        }
    }
};
