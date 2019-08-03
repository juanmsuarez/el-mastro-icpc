#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define all(v) v.begin(), v.end()
#define pb emplace_back
#define si(a) int(a.size())
using ll = long long int;
using vi = vector<int>;

struct pto {
    ll x, y;
    pto (ll x = 0, ll y = 0) : x(x), y(y) {}

    pto operator - (pto a) { return pto(x - a.x, y - a.y); }

    ll operator ^ (pto a) { return x*a.y - y*a.x; }

    bool left(pto q, pto r) { return ((q-*this) ^ (r-*this)) > 0; }
    bool operator < (const pto &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator == (const pto &a) const {
        return x == a.x && y == a.y;
    }
};
using vp = vector<pto>;

void chull(vp &v, vp &w) {
    w.clear();
    sort(all(v));

    for (pto p : v) {
        while (si(w) >= 2 && w[si(w)-1].left(w[si(w)-2], p)) w.pop_back();
        w.pb(p);
    }
    w.pop_back();

    int k = si(w);
    reverse(all(v));
    for (pto p : v) {
        while (si(w) >= k+2 && w[si(w)-1].left(w[si(w)-2], p)) w.pop_back();
        w.pb(p);
    }
    w.pop_back();
}

int main(){
    int n; cin >> n;
    vp v(n); for (pto &p : v) cin >> p.x >> p.y;
    int m; cin >> m;
    vp w(m); for (pto &p : w) cin >> p.x >> p.y;

    vp ps = v; ps.insert(ps.end(), all(w));
    vp chps; chull(ps, chps);

    sort(all(v));
    sort(all(chps));

    cout << (chps == v ? "YES" : "NO") << endl;

    return 0;
}
