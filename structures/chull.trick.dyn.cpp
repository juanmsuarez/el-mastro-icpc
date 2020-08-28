// Default is max, change a,b to -a,-b and negate the result for min
// If the lines use real vals change div by a/b and the comparisons
struct Line {
    ll a, b; mutable ll p;
    bool operator<(const Line& o) const { return a < o.a; }
    bool operator<(ll x) const { return p < x; }
};
struct CHT : multiset<Line, less<>> {
    ll div(ll a, ll b) { return a/b - ((a^b) < 0 && a % b); } // floor(a/b)
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = INF, false;
        if (x->a == y->a) x->p = x->b > y->b ? INF : -INF;
        else x->p = div(y->b - x->b, x->a - y->a);
        return x->p >= y->p;
    }
    void add(ll a, ll b) {
        auto z = insert({a, b, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound(x);
        return l.a * x + l.b;
    }
};
