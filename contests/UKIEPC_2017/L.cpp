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
#ifdef LOCAL
    #define DBG(a) //cerr << #a << "=" << a << endl
    #define RAYA //cerr << "----------" << endl
#else
    #define DBG(a)
    #define RAYA
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

struct point {
    tint x, y;
    int h;
    point(tint x=0, tint y=0, int h = 0) : x(x), y(y), h(h) {}

    double ang(point o) {
        return atan2(o.y-y, o.x-x);
    }
};

const double EPS = 1e-9;
const int MAXN = 1e6+10, INF = 1e9;
point o, c[MAXN];

tint dist2(point a, point b) {
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

//Para non-increasing, cambiar comparaciones y revisar busq binaria
//Given an array, paint it in the least number of colors so that each color turns to a non-increasing subsequence.
//Solution:Min number of colors=Length of the longest increasing subsequence
int N, a[MAXN];//secuencia y su longitud
pii d[MAXN+1];//d[i]=ultimo valor de la subsecuencia de tamanio i
int p[MAXN];//padres
vector<int> R;//respuesta
void rec(int i){
	if(i==-1) return;
	R.pb(a[i]);
	rec(p[i]);
}
int lis(){//O(nlogn)
	d[0] = pii(-INF, -1); forn(i, N) d[i+1]=pii(INF, -1);
	forn(i, N){
		int j = upper_bound(d, d+N+1, pii(a[i], INF))-d;
		if (d[j-1].first < a[i]&&a[i] < d[j].first){
			p[i]=d[j-1].second;
			d[j] = pii(a[i], i);
		}
	}
	R.clear();
	dforsn(i, 0, N+1) if(d[i].first!=INF){
		rec(d[i].second);//reconstruir
		reverse(R.begin(), R.end());
		return i;//longitud
	}
	return 0;
}

int main() {
    fastio;

    cin >> o.x >> o.y; 

    int n;
    cin >> n;
    forn(i, n)
        cin >> c[i].x >> c[i].y >> c[i].h;

    sort(c, c+n, [](point a, point b) {
        if (abs(a.ang(o) - b.ang(o)) < EPS) return dist2(a, o) < dist2(b, o);
        else return a.ang(o) < b.ang(o);
    });
    
    int i = 0, ans = 0;
    while (i < n) {
        int j = 0;
        point last = c[i];
        //cerr << i << ' ' << c[i].x << ' ' << c[i].y << endl;
        while (i < n && abs(c[i].ang(o) - last.ang(o)) < EPS) {
            //cerr << "pend1 " << last.ang(o) << endl;
            //cerr << "pend2 "  << c[i].ang(o) << endl;
            //cerr << "agrego " << c[i].x << ' ' << c[i].y << ' ' << c[i].h << endl;
            a[j] = c[i].h;
            last = c[i];
            i++, j++;
        }
        N = j;
        ans += lis();
        //cerr << "Lis " << lis() << endl << endl;
    }

    cout << ans << endl;

    return 0;
}
