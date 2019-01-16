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

const int MAXN =1e4+10;

int p[MAXN];
void init() { forn(i, MAXN) p[i] = i; }

int find(int x) { return p[x] = p[x] == x ? x : find(p[x]); }

bool merge(int x, int y) {
	int px = find(x), py = find(y);
	p[px] = py;
	return px != py;
}

struct edge {
	int u, v, d;
	edge(int u, int v, int d) : u(u), v(v), d(d) {}
	
	bool operator < (const edge &b) const {
		return d > b.d;
	}
};

vector<edge> e;
int mx = 0;

int kruskal() {
	int cost = 0;
	sort(e.begin(), e.end());
	forn(i, si(e)) {
		if (merge(e[i].u, e[i].v)) {
			cost += e[i].d;
		}
		else {
			
			mx = max(mx, e[i].d);
		}
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int s, l;
	cin >> s >> l;
	
	init(); 
	
	int sum = 0;
	forn(i, l) {
		int u, v, d;
		cin >> u >> v >> d;
		sum += d;
		e.pb(edge(u,v,d));
	}
	
	cout << sum-kruskal();
	cout << ' ' << mx << endl;

	return 0;
}
