#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

struct point {
    double x, y;
};

const int MAXN = 1e6+10;
const double INF = 1LL<<60, EPS = 1e-9;

int n;
point p[MAXN];

double dist2(point a, point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

inline double len(double a, double b) {
    point y = {0, b}, x = {-b/a, 0};

    return dist2(x, y);
}

double f(double a) {
    double b = 0;

    forn(i, n) 
        if (a*p[i].x+b <= p[i].y)
            b = p[i].y - a*p[i].x;

    return len(a, b);
}

int main() {
    fastio;

    while (cin >> n) {
        forn(i, n) cin >> p[i].x >> p[i].y; 

        double lo = -INF, hi = -EPS;
        forn(_, 200) {
            double mid1 = lo+(hi-lo)/3, mid2= hi-(hi-lo)/3;

            if (f(mid1) < f(mid2)) hi = mid2;
            else lo = mid1;
        }

        cout << fixed << setprecision(3) << sqrt(f(lo)) << endl;
    }

    return 0;
}
