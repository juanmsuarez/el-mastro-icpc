#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 100+10;
const double INF = 1LL<<60, eps = 1e-9;
int n;
tint cx[MAXN], cy[MAXN], f[MAXN];
bool vis[MAXN];
double a[MAXN][MAXN], d[MAXN];

double dijkstra() {
	fill(d, d+n+2, INF);
	fill(vis, vis+n+2, false);
	
	d[n] = 0;
	//cout << d[0] << ' ' << d[n] << endl;
	while (true) {
		int umin = -1;
		double mn = INF;
		forn(u, n+2) if (!vis[u] && d[u] < mn ) {
			mn = d[u];
			umin = u;
		}
		
		//cout << "llegue a " << umin << " con min dist " << d[umin] << endl;
		
		if (umin == -1) break;
		vis[umin] = true;
		
		forn(v, n+2)
			if (d[umin] + a[umin][v] < d[v]) {
				//cerr << "act " << v << endl;
				d[v] = d[umin] + a[umin][v];
			}
	}
	
	return d[n+1];
}

double dist(double ax, double ay, double bx, double by) {
	return sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay));
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int px, py, lx, ly;
	cin >> n >> px >> py >> lx >> ly;
	
	fill(a[0], a[n+2], INF);
	
	forn(i, n) {
		cin >> cx[i] >> cy[i] >> f[i];
		a[n][i] = dist(px, py, cx[i], cy[i]);
		a[i][n+1] = min(abs(dist(cx[i], cy[i], lx, ly) - f[i]),dist(cx[i], cy[i], lx, ly));
		//cout << "d " << dist(px, py, cx[i], cy[i]) << ' ' << min(abs(dist(cx[i], cy[i], lx, ly) - f[i]),dist(cx[i], cy[i], lx, ly)) << endl;
	}
	a[n][n+1] = dist(px,py, lx, ly);
	
	forn(i, n) forn(j, n) {
		a[i][j] = min(abs(dist(cx[i], cy[i], cx[j], cy[j]) - f[i]),dist(cx[i], cy[i], cx[j], cy[j]));
		a[j][i] = min(abs(dist(cx[i], cy[i], cx[j], cy[j]) - f[j]),dist(cx[i], cy[i], cx[j], cy[j]));
	}
	
	cout << fixed << setprecision(2);
	cout << dijkstra() << endl;
	
	return 0;
}
