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

const double EPS=1e-9;
struct pto {
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	double norm(){return sqrt(x*x+y*y);}
    bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
};
double dist(pto a, pto b){return (b-a).norm();}

const int N = 18, M = 1<<N, INF = 1e9;
int w, h, n;
pto p[N+1]; 
double memo[N+1][M]; 

double cost(pto &a, pto &b) {
    if (a == p[n]) return dist(a, b);

    double ans = INF;

    auto reflexes = {pto(-b.x, b.y), pto(b.x, -b.y), pto(2*w-b.x, b.y), pto(b.x, 2*h-b.y)};
    for (auto br : reflexes)
        ans = min(ans, dist(a, br));

    return ans;
}

double dp(int last, int mask) {
    if (mask == 0) return min({p[last].x, w-p[last].x, p[last].y, h-p[last].y});

    double &res = memo[last][mask];
    if (res != INF) return res;

    forn(nxt, n) if (mask & (1<<nxt))
        res = min(res, dp(nxt, mask ^ (1<<nxt)) + cost(p[last], p[nxt]));

    return res;
}

int main() {
	fastio;
	
    int t; cin >> t;
    while (t--) {
        cin >> w >> h >> n;
        forn(i, n) cin >> p[i].x >> p[i].y;

        cin >> p[n].x >> p[n].y;

        fill(memo[0], memo[N+1], INF);
        cout << fixed << setprecision(6) << dp(n, (1<<n)-1) << endl;
    }
	
	return 0;
}
