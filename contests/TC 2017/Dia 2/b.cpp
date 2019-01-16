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

const int MAXN = 1e4+10;
vi adj[MAXN];
int dm, far;

void go(int u, int p, int d) {
	if (d > dm) {
		dm = d;
		far = u;
	}
	
	forn(i, si(adj[u])) {
		int v = adj[u][i];
		if (v != p)
			go(v, u, d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif

	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		forn(u, n)
			adj[u].clear();
		
		forn(i, n-1) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			
			adj[a].pb(b); 
			adj[b].pb(a);
		}
		dm=-1;
		go(0, -1, 0);
		dm=-1; 
		go(far, -1, 0);
		cout << dm+1 << endl;
	}

	return 0;
}
