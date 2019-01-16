#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

struct car {
    int pos; ll t; int ind;
    car(int pos=0, ll t=0, int ind=0) : pos(pos), t(t), ind(ind) {}
};

struct availableu {
    bool operator () (const car &a, const car &b) const {
        return a.pos < b.pos || 
            (a.pos == b.pos && a.t < b.t) || 
            (a.pos == b.pos && a.t == b.t && a.ind < b.ind);
    }
};
struct availabled {
    bool operator () (const car &a, const car &b) const {
        return a.pos > b.pos || 
            (a.pos == b.pos && a.t < b.t) || 
            (a.pos == b.pos && a.t == b.t && a.ind < b.ind);
    }
};

struct busy {
    bool operator () (const car &a, const car &b) const {
        return a.t > b.t;
    }
};


int main() {
    fastio;

    int n, k, m;
    cin >> n >> k >> m;

    set<car, availableu> au;
    set<car, availabled> ad;
    priority_queue<car, vector<car>, busy> b;
    forn(i, k) {
        int p; cin >> p;
        au.insert((car){p, 0, i}); 
        ad.insert((car){p, 0, i});
    }

    ll t = 0;
    forn(i, m) {
        ll tact; int x, y;    
        cin >> tact >> x >> y;
        t = max(t, tact);
        
        while (!b.empty() && (b.top().t <= t || au.empty())) {
            //cerr << "saco " << b.top().pos << ' ' << b.top().t << ' ' << b.top().ind << endl;

            au.insert(b.top());
            ad.insert(b.top());

            t = max(t, b.top().t);

            b.pop();
        }        

        car c;
        auto r = au.lower_bound({x, -LLONG_MAX, -INT_MAX}); 
        auto l = ad.lower_bound({x, LLONG_MAX, INT_MAX});
        if (r == au.end()) c = *l;
        else if (l == ad.end()) c = *r;
        else {
            car lc = *l, rc = *r;
            if (availableu()({abs(x-lc.pos), lc.t, lc.ind}, {abs(x-rc.pos), rc.t, rc.ind}))
                c = lc;
            else
                c = rc;
        }

        /*
        cerr << "elijo " << c.pos << ' ' << c.t << ' ' << c.ind << endl;

        cerr << "si" << endl;
        cerr << si(au) << ' ' << si(ad) << endl;
        */
        au.erase(c);
        ad.erase(c);
        /*
        cerr << si(au) << ' ' << si(ad) << endl;
        cerr << "si" << endl;
        */

        cout << c.ind+1 << ' ' << t+abs(x-c.pos)-tact << endl;

        /*
        cerr << "agrego " << y << ' ' << t+abs(x-c.pos)+abs(x-y) << ' ' <<
        c.ind << endl;
        */
        b.push({y, t+abs(x-c.pos)+abs(x-y), c.ind});
    }

    return 0;
}
