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

const int MAXN = 1e6+10;
bool used[MAXN];
enum color { blanco, gris, negro };
color c[MAXN];
bool ciclo;
vi v, adj[MAXN];

void topo(int u) {
	c[u] = gris;
	
	forn(i, si(adj[u])) {
		int v = adj[u][i];
		if (c[v] == gris) ciclo = true;
		else if (c[v] == blanco)
			topo(v);
	}
	
	v.pb(u);
	c[u] = negro;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int n, m;
	while (cin >> n >> m && n != 0) {
		ciclo = false;
		v.clear();
		forn(u, n) {
			used[u] = false;
			c[u] = blanco;
			adj[u].clear();
		}
		
		forn(i, m) {
			int a, b;
			cin >> a >> b;
			a--;b--;
			adj[a].pb(b);
		}
		
		forn(u, n)
			if (c[u] == blanco)
				topo(u);
		
		if (!ciclo) {
			reverse(v.begin(), v.end());
			forn(i, si(v)) cout << v[i]+1 << endl;
		}
		else cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
