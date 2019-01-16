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

const int MAXN = 2e3+10, MAXM = 3e3+10;

struct edge {
	int a,b,d;
	edge(int a=0, int b=0,int d=0) : a(a), b(b), d(d) {}
	
	bool operator < (const edge &b) const {	
		return d < b.d;
	}
};

int n;
edge ve[MAXM];
bool vis[MAXN];
vi adj[MAXN];

void dfs(int u) {
	vis[u] = true;
	
	//cout << "llego a " << u << endl;
	
	forn(i, si(adj[u])) {
		int v = adj[u][i];
		if (!vis[v])
			dfs(v);
	}
}

int main() {
	//ios_base::sync_with_stdio(false); 
	//cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int r, s, e;
	cin >> n >> r >> s >> e;
	forn(i, r) {
		int a, b, d;
		cin >> a >> b >> d;
		ve[i] = edge(a,b,d);
	}
	sort(ve, ve+r);
	
	int res = INT_MAX;
	int j = 0;
	forn(i, r) {
		fill(vis, vis+n, false);
		//forn(i, n) cout << "vis " << i << ' '<< vis[i] << endl;
		dfs(s);
		while (j < r && !vis[e]) {
			adj[ve[j].a].pb(ve[j].b);
			adj[ve[j].b].pb(ve[j].a);
			//cout << "agrego " << ve[j].a << ' ' << ve[j].b << endl;
			
			fill(vis, vis+n, false);
			dfs(s);

			j++;
		}
	
		//cout << "LLEGO " << vis[e] << endl;
		if (!vis[e]) break;	
		
		res = min(res, ve[j-1].d - ve[i].d); 
		//cout << i << ' ' << j << endl;
		//cout << "res " << res << endl;
		
		//cout << "saco " << ve[i].a << ' ' << ve[i].b << endl;	 
		adj[ve[i].a].erase(find(adj[ve[i].a].begin(), adj[ve[i].a].end(), ve[i].b));
		adj[ve[i].b].erase(find(adj[ve[i].b].begin(), adj[ve[i].b].end(), ve[i].a));
	}
	
	if (res == INT_MAX) cout << "NO PATH" << endl;
	else cout << res << endl;

	return 0;
}
