// Default is max, change a,b to -a,-b and negate the result for min
struct LiChaoTree { 
    struct Line { ll a, b; ll operator()(ll x) { return a*x + b; } };
    struct Node { Node *l=0, *r=0; Line v; Node(Line o) { v = o; } };

    Node *root = 0; static const ll N = 1e6+1; // x range = [-N, N)
    void add(ll a, ll b) { add(Line{a, b}, -N, N, root); } // a*x + b = 0
    ll eval(ll x) { return eval(x, -N, N, root); }

    void add(Line v, ll l, ll r, Node* &c) {
        if (!c) { c = new Node(v); return; }
        bool bestl = v(l) > c->v(l);
        bool bestr = v(r-1) > c->v(r-1);
        if (bestl && bestr) { c->v = v; return; }
        if (!bestl && !bestr) return; 
        if (bestl) swap(v, c->v); // v.a < c->v.a
        ll m = (l + r) / 2;
        if (v(m) > c->v(m)) swap(v, c->v), add(v, l, m, c->l);
        else add(v, m, r, c->r);
    }
    ll eval(ll x, ll l, ll r, Node* &c) {
        if (!c) return -INF;
        if (l+1 == r) return c->v(x);
        ll m = (l + r) / 2;
        return max(c->v(x), x < m ? 
            eval(x, l, m, c->l) : eval(x, m, r, c->r));
    }
    /* Add the next two lines to free memory after use if needed:
    void clear() { del(root), root = 0; }
    void del(Node* &c) { if (!c) return; del(c->l), del(c->r), delete c; } */
};
