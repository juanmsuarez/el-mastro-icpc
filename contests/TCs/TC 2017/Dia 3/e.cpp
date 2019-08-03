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

const int MAXN = 1e3+10;
int sal[MAXN], sig[MAXN];
vi adj1[MAXN], adj2[MAXN];
bool vis[MAXN], res[MAXN], emp[MAXN][MAXN];

void go(int u, int e) {
	res[u] = true;
	vis[u] = true;
	
	forn(i, si(adj1[u])) {
		int v = adj1[u][i];
		if (!vis[v]) 
			go(v, e);
		if (!res[v]) {
			res[u] = false;
			break;
		}
	}
	
	if (emp[u][e] && res[u]) {
		res[u] = false;
		sal[e] += sig[u];
	}
}

void calcSig(int u) {
	vis[u] = true;
	
	forn(i, si(adj2[u])) {
		int v = adj2[u][i];
		if (!vis[v])
			calcSig(v);
		sig[u] += sig[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int t, e;
	while (cin >> t >> e && t != 0) {
		forn(u,t) {
			adj1[u].clear();
			adj2[u].clear();
			sig[u] = 0;
			vis[u] = false;
		}
		forn(u, e)
			sal[u] = 0;
		forn(u, t) forn(ee, e) emp[u][ee] = false;
		
		forn(u, t) {
			int bs, nd, ne;
			cin >> bs >> nd >> ne;
	
			sig[u] = bs;
	
			forn(i, nd) {
				int v;
				cin >> v;
				v--;
				adj1[v].pb(u);
				adj2[u].pb(v);
			}
			forn(i, ne) {
				int ee;
				cin >> ee;
				ee--;
				emp[u][ee]= true;
			}
		 } 
		
		forn(u, t) 
			if (!vis[u])
				calcSig(u);
	
		forn(ee, e) {
			forn(u, t)
				res[u] = vis[u] = false;
			
			forn(u, t)
				if (!vis[u])
						go(u, ee);
		}
			
		cout << "*****" << endl;
		forn(i, e)
			cout << i+1 << ' ' << sal[i] << endl;
	}

	return 0;
}
