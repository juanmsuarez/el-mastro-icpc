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

const int MAXN = 20000+10;
vi adj[MAXN];
// id[i] = -2: descubierto, stackeado. -1: no descubierto. >= 0: numero de componente
int ticks, ncomp, low[MAXN], id[MAXN], disc[MAXN];
stack<int> s;

void init() {
	ticks = ncomp = 0;
	fill(disc, disc+MAXN, 0);
	fill(id, id+MAXN, -1);
}

void tarjan(int u) {
	low[u] = disc[u] = ++ticks;
	id[u] = -2;
	s.push(u);
	
	forn(i, si(adj[u])) {
		int v = adj[u][i];
		if (!disc[v] || id[v] == -2) {
			if (!disc[v]) tarjan(v);
			low[u] = min(low[u], low[v]);
		}
	}
	
	if (low[u] == disc[u]) { // es raiz
		int v; 
		do { 
			v = s.top(); 
			s.pop(); 
			id[v] = ncomp; 
		} while (v != u);
		ncomp++;
	}
}


int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int nc;
	cin >> nc;
	while (nc--) {
		int n, m;
		cin >> n >> m;
		
		forn(i, m) {
			int a, b;
			cin >> a >> b;
			r
		}
		
		init();
		forn(u, n)
			if (!disc[u])
				tarjan(u);

	}	
	return 0;
}
