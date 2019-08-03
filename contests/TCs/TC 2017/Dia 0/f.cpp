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

const int MAXN = 10;


struct nodo { 
	int u, v, ts;
	
	nodo(int u, int v, int ts) : u(u), v(v), ts(ts) {}
};

int ts[MAXN];
vector<nodo> adj[MAXN][MAXN][110];
bool used[MAXN][MAXN][110];
vector<nodo> lista, sol;

void topo(nodo u) {
	used[u.u][u.v][u.ts] = true;
	
	for (nodo v : adj[u.u][u.v][u.ts])
		if (!used[v.u][v.v][v.ts])
			topo(v);
			
	lista.pb(u);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	freopen("in.txt","r",stdin); 
	
	int n;
	while (cin >> n && n != -1) {
		lista.clear();
		sol.clear();
		forn(i, n)
			forn(j, n) forn(k, 100) adj[i][j][k].clear(), used[i][j][k]=false;
			
		vector<nodo> nodos;
		
		forsn(u, 1, n) {
			fill(ts, ts+MAXN, 0);
			
			vector<nodo> act;
			string s;
			cin >> s;
			
			forn(i, si(s)) {
				int v = s[i] - '0' - 1;
				nodo n = nodo(min(u,v),max(u,v),ts[v]++);
				nodos.pb(n);
				act.pb(n);
			}
			forn(i, si(act))
				forsn(j,i+1,si(act))
					adj[act[i].u][act[i].v][act[i].ts].pb(act[j]);
		}
		
		forn(i, si(nodos)) 
			if (!used[nodos[i].u][nodos[i].v][nodos[i].ts])
				topo(nodos[i]);
				
		reverse(lista.begin(),lista.end());
		forn(i, si(lista)) {
			if (lista[i].u == 0)
				cout << lista[i].v+1;
			if (lista[i].v == 0)
				cout << lista[i].u+1;
		}
		cout << endl;
	}

	return 0;
}
