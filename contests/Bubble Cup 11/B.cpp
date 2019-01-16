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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 1e5+10, LOGN = 20;
struct bridge {

	struct edge {
		int u,v, comp;
		bool bridge;
	};

	int n;
	vi adj[MAXN];
	vector<edge> e;

    #define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
	bridge(int n=0): n(n) {
		e.clear();
		initDfs();
	}

	void initDfs() {
		nbc = t = 0;
        forn(u, n) d[u] = -1;
	}

	void addEdge(int u, int v) {
		adj[u].pb(si(e)); adj[v].pb(si(e));
		e.pb((edge){u,v,-1,false});
	}


    //d[i]=id de la dfs
    //b[i]=lowest id reachable from i
	int d[MAXN], b[MAXN], t, nbc; bool art[MAXN];
	int comp[MAXN];
	stack<int> st;
	void dfs(int u=0, int pe=-1) {
		b[u] = d[u] = t++;
		comp[u] = (pe != -1);

		forn(i,si(adj[u])) {
			int ne = adj[u][i];
			if (ne == pe) continue;
			int v = e[ne].u ^ e[ne].v ^ u;
			if (d[v] == -1) {
				st.push(ne);
				dfs(v,ne);
				if (b[v] > d[u]) e[ne].bridge = true; // bridge
				if (b[v] >= d[u]) { // art
					int last;
					do {
						last = st.top(); st.pop();
						e[last].comp = nbc;
					} while (last != ne);
					nbc++;
                    art[u] = true;
					comp[u]++;
				} 
				b[u] = min(b[u], b[v]);
			}
			else if (d[v] < d[u]) { // back edge
				st.push(ne);
				b[u] = min(b[u], d[v]);
			}
		}
	}
};

vi adj[2*MAXN];
int f[2*MAXN][LOGN], L[2*MAXN];

void dfs(int u=0, int p=-1, int l=0) {
    f[u][0]=p, L[u]=l;
    for (int v : adj[u])
       if (v != p)
          dfs(v, u, l+1); 
}
void build(){//f[i][0] must be filled previously, O(nlgn)
    forn(k, LOGN-1) forn(i,MAXN) if (f[i][k]!=-1) f[i][k+1]=f[f[i][k]][k];
}
int climb(int a, int d){//O(lgn)
    if(!d) return a;
    dforsn(i,0, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;}
int lca(int a, int b){//O(lgn)
    if(L[a]<L[b]) swap(a, b);
    a=climb(a, L[a]-L[b]);
    if(a==b) return a;
    dforsn(i,0, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
    return f[a][0]; }
int dist(int a, int b) {//returns distance betweenMAXNodes
    return L[a] + L[b] - 2*L[lca(a,b)];
}

int main() {
	fastio;
	
    int n, m, q; cin >> n >> m >> q;
    bridge b(n);
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        b.addEdge(u,v);
    }
    b.dfs();

    forn(u, n) {
        vi comps;
        for (int ne : b.adj[u]) {
            auto &e = b.e[ne];
            comps.pb(e.comp);
        }
        sort(all(comps)); comps.erase(unique(all(comps)), comps.end());
        for (int c : comps) {
            //cerr << u << ' ' << n+c << endl;
            adj[u].pb(n+c), adj[n+c].pb(u);
        }
    }

    dfs();
    build();

    while (q--) {
        int u, v; cin >> u >> v; u--, v--;

        cout << dist(u,v)/2 << endl;
    }
	
	return 0;
}


