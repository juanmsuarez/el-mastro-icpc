#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;
using vd = vector<double>;

const ll INF = 1e18;

int main() {
	fastio;
	
    int n; cin >> n;
    vd a(n); forn(i, n) cin >> a[i];

    auto f = [n, a](double k) {
        vd pos(n), neg(n);
        forn(i, n) pos[i] = a[i] - k, neg[i] = -pos[i];

        auto calc = [](vd &a) {
            double res = 0, acum = 0;
            for (auto &x : a) {
                acum = max(acum+x, x);
                res = max(res, acum);
            }
            return res;
        };

        return max(calc(pos), calc(neg));
    };

    double lo = -INF, hi = +INF;
    forn(_, 200) {
        double l = lo + (hi - lo) / 3, r = hi - (hi - lo) / 3;
        if (f(l) < f(r)) hi = r;
        else lo = l;
    }

    cout << fixed << setprecision(6) << f(lo) << endl;
	
	return 0;
}
