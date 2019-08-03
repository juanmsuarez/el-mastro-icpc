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
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 5e5+10;
const double EPS = 1e-9, INF = DBL_MAX;
int n, x[MAXN], v[MAXN];

bool can(double t) {
    vector<double> nx;
    nx.pb(-INF);
    forn(i, n) {
        double d = -INF;

        if (v[i] > 0)
            d = x[i] + v[i] * t;
        
        nx.pb(max(nx.back(), d)); 
        //cerr << i+1 << ' ' << nx.back() << endl;
    }

    bool res = false;
    dforsn(i, 0, n) {
        if (v[i] < 0) {
            double d = x[i] + v[i] * t;
            //cerr << d << " vs " << nx[i] << endl;
            if (d < nx[i] + EPS) res = true;
        }
    }    

    return res;
}

int main() {
    fastio;

    cin >> n;
    forn(i, n) cin >> x[i] >> v[i];

    double lo = 0, hi = 2e9+10;

    if (!can(hi)) cout << -1 << endl;
    else {
        forn(_, 100) {
            double mid = (lo + hi) / 2;

            if (can(mid)) hi = mid;
            else lo = mid;
        }

        cout << fixed << setprecision(10) << hi << endl;
    }

    return 0;
}
