#include <bits/stdc++.h>
using namespace std;

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
using pdd = pair<double, double>;

const double EPS = 1e-10, INF = 1e9;

struct pto {
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
};

pto rs, re; 

pdd intersectionTimes(pto p, pto v) {
    auto timeDist = [](double p, double s, double e, double vel) {
        if (abs(vel) < EPS) return p > s && p < e ? mp(0., INF) : mp(INF, INF);
        double st = max(0., (s - p)/vel), et = max(0., (e - p)/vel);
        if (et < st - EPS) swap(st, et);
        return mp(st, et);
    };

    double xs, xe; tie(xs, xe) = timeDist(p.x, rs.x, re.x, v.x);
    double ys, ye; tie(ys, ye) = timeDist(p.y, rs.y, re.y, v.y);

    return {max(xs, ys), min(xe, ye)};
}

int main() {
	fastio;

    int n; 
    while (cin >> n) {
        cin >> rs.x >> rs.y >> re.x >> re.y;

        double lo = 0, hi = INF;
        while (n--) {
            pto p, v; cin >> p.x >> p.y >> v.x >> v.y;
            double ts, te; tie(ts, te) = intersectionTimes(p, v);
            lo = max(lo, ts);
            hi = min(hi, te);
        }

        cout << fixed << setprecision(6) << (lo < hi - EPS ? lo : -1) << endl;
    }

	return 0;
}
