namespace LinkCut {
    // OPERATIONS ON PATHS: MODIFY HERE!
    const int N_DEL = 0, N_VAL = 0; // neutral values: delta, value
    int mOp(int x, int y) { return x + y; } // modify operation
    int qOp(int lval, int rval) { return lval + rval; } // query operation
    int dOnSeg(int d, int len) { return d == N_DEL ? N_DEL : d * len; } // calc delta on segment

    // GENERIC OPERATIONS
    int mergeD(int d1, int d2) { // Merge two deltas
        if (d1 == N_DEL) return d2;
        if (d2 == N_DEL) return d1;
        return mOp(d1, d2);
    }
    int mergeVD(int v, int d) { // Merge value and delta
        return d == N_DEL ? v : mOp(v, d);
    }

    // SPLAY TREE STRUCT
    struct Node_t {
        int sz, nVal, tVal, d; // nVal: node value, tVal: tree value, d: delta
        bool rev;
        Node_t *c[2], *p; // c: children (right, left)

        Node_t(int v = N_VAL): sz(1), nVal(v), tVal(v), d(N_DEL), rev(0), p(0) {
            c[0] = c[1] = 0;
        }

        bool isRoot() {
            return !p || (p->c[0] != this && p->c[1] != this);
        }
        void push() {
            if (rev) {
                rev = 0;
                swap(c[0], c[1]);
                forn(x, 2) if (c[x]) c[x]->rev ^= 1;
            }
            nVal = mergeVD(nVal, d);
            tVal = mergeVD(tVal, dOnSeg(d, sz));
            forn(x, 2) if (c[x]) c[x]->d = mergeD(c[x]->d, d);
            d = N_DEL;
        }
        void upd();
    };
    using Node = Node_t*;

    // SPLAY TREE OPS
    int getSize(Node r) {
        return r ? r->sz : 0;
    }
    int getPathVal(Node r) {
        return r ? mergeVD(r->tVal, dOnSeg(r->d, r->sz)) : N_VAL;
    }
    void Node_t::upd() {
        tVal = qOp(qOp(getPathVal(c[0]), mergeVD(nVal, d)), getPathVal(c[1]));
        sz = 1 + getSize(c[0]) + getSize(c[1]);
    }
    void conn(Node c, Node p, int il) {
        if (c) c->p = p;
        if (il >= 0) p->c[!il] = c;
    }
    void rotate(Node x) {
        Node p = x->p, g = p->p;
        bool gCh = p->isRoot(), isl = x == p->c[0];
        conn(x->c[isl], p, isl);
        conn(p, x, !isl);
        conn(x, g, gCh ? -1 : (p == g->c[0]));
        p->upd();
    }
    void splay(Node x) {
        while (!x->isRoot()) {
            Node p = x->p, g = p->p;
            if (!p->isRoot()) g->push();
            p->push();
            x->push();
            if (!p->isRoot()) rotate((x == p->c[0]) == (p == g->c[0]) ? p : x);
            rotate(x);
        }
        x->push();
        x->upd();
    }

    // LINK-CUT-TREE OPS
    Node access(Node x) {
        Node last = 0;
        for (Node y = x; y; y = y->p) {
            splay(y);
            y->c[0] = last;
            y->upd();
            last = y;
        }
        splay(x);
        return last;
    }
    void makeRoot(Node x) {
        access(x);
        x->rev ^= 1;
    }
    Node getRoot(Node x) {
        access(x);
        while (x->c[1]) x = x->c[1];
        splay(x);
        return x;
    }
    Node lca(Node x, Node y) {
        access(x);
        return access(y);
    }
    bool connected(Node x, Node y) {
        access(x);
        access(y);
        return x == y ? 1 : x->p != 0;
    }
    void link(Node x, Node y) {
        makeRoot(x);
        x->p = y;
    }
    void cut(Node x, Node y) {
        makeRoot(x);
        access(y);
        y->c[1]->p = 0;
        y->c[1] = 0;
    }
    Node father(Node x) {
        access(x);
        Node r = x->c[1];
        if (!r) return 0;
        while (r->c[0]) r = r->c[0];
        return r;
    }
    void cut(Node x) {
        access(father(x));
        x->p = 0;
    }
    int query(Node x, Node y) {
        makeRoot(x);
        access(y);
        return getPathVal(y);
    }
    void modify(Node x, Node y, int d) {
        makeRoot(x);
        access(y);
        y->d = mergeD(y->d, d);
    }
    Node lift_rec(Node x, int t) {
        if (!x) return 0;
        if (t == getSize(x->c[0])) {
            splay(x);
            return x;
        }
        if (t < getSize(x->c[0])) return lift_rec(x->c[0], t);
        return lift_rec(x->c[1], t - getSize(x->c[0]) - 1);
    }
    Node lift(Node x, int t) {
        access(x);
        return lift_rec(x, t);
    }
    int depth(Node x) {
        access(x);
        return getSize(x) - 1;
    }
};
// USO: LinkCut::Node nodes[N]; nodes[u] = new LinkCut::Node_t(); LinkCut::link(nodes[u], nodes[v]);
