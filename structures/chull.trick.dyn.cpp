using ld = long double;
const ld EPS = 1e-9, INF = 2e18;
#define less_equal(a,b) ((a) < (b) + EPS)
bool query, qmax; // qmax = 1: queries return max
struct line {
    ll a,b; ld i;
    line(ll _a, ll _b, ld _i) { a=_a, b=_b, i=_i; }
    bool operator<(const line &l) const {
        return query ? i < l.i : (qmax ? a < l.a : a > l.a);
    }
};
struct CHT {
    set<line> s;
    ld inter(const line &x, const line &y) {
        return ld(x.b - y.b) / (y.a - x.a);
    }
    bool improves(const line &x, const line &y, const line &z) {
        return less_equal(inter(x, z), inter(x, y));
    }
    void insert(ll a, ll b) { // ax + b = 0
        query = false;
        line v = {a,b,0};
        auto l = s.lower_bound(v);
        bool add = l == s.end() || (a == l->a && (qmax ? b > l->b : b < l->b)) ||
             (a != l->a && (l == s.begin() || !improves(*prev(l), v, *l)));
        if (!add) return;
        bool first = l == s.begin();
        auto f = l, p = l;
        if (l != s.end() && a == l->a) l++;
        if (!first) {
            p = prev(p);
            while (p != s.begin() && improves(*prev(p), *p, v)) f = p, p = prev(p);
        } 
        if (l != s.end()) {
            auto n = next(l);
            while (n != s.end() && improves(v, *l, *n)) l = n, n = next(n);
        } 
        if (f != l) s.erase(f, l);
        if (l != s.end()) {
            ld i = inter(v, *l);
            ll c = l->a, d = l->b; 
            s.erase(l), s.emplace(c, d, i);
        }
        if (first) s.emplace(a, b, -INF);
        else s.emplace(a, b, inter(*p, v));
    }
    ll eval(ld x) {
        query = true;
        auto &l = *prev(s.upper_bound({0,0,x}));
        return l.a * x + l.b;
    }
} cht;
