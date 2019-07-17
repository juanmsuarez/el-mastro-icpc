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
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct bridge {
	struct edge {
		int u,v,comp;
		bool bridge;
	};

	int n,t,nbc;//nbc= number of biconnected components
	vi d,b,comp;
    //d[i]=id de la dfs
    //b[i]=lowest id reachable from i
    //comp[i] = cant de componentes biconexas a las que pertenece i
	stack<int> st;
    vector<vi> adj;
	vector<edge> e;

	bridge(int n=0): n(n) {
		adj = vector<vi>(n);
		e.clear();
		initDfs();
	}

	void initDfs() {
        d = vi(n), b = vi(n), comp = vi(n);
        forn(i,n) d[i] = -1;
        nbc = t = 0;
	}

	void addEdge(int u, int v) {
		adj[u].pb(si(e)); adj[v].pb(si(e));
		e.pb((edge){u,v,-1,false});
	}

	void dfs(int u=0, int pe=-1) {
		b[u] = d[u] = t++;
        comp[u] = pe != -1;

		for(int ne : adj[u]) {
			if(ne == pe) continue; 
			int v = e[ne].u ^ e[ne].v ^ u;
			if(d[v] == -1) {
				st.push(ne);
				dfs(v,ne);
				if(b[v] > d[u]) e[ne].bridge = true; // bridge
				if(b[v] >= d[u]) { // art
					int last;
					do {
						last = st.top(); st.pop();
						e[last].comp = nbc;
					} while(last != ne);
					nbc++, comp[u]++;
				} 
				b[u] = min(b[u], b[v]);
			}
			else if(d[v] < d[u]) { // back edge
				st.push(ne);
				b[u] = min(b[u], d[v]);
			}
		}
	}
}compb;

struct block-cut{

    vector<vi> ady;
    vector<bool> artpoints;
    void build(bridge comps){
        ady= vi(comps.nbc);
        artpoints= vector<bool>(si(ady));
        forn(u,si(comps.ady)){
            if(comps.comp[u]>1){
                vi adycomps();
                for(i:comps.ady[u]){
                    bridge.edge e = comps.e[i];
                    adycomps.pb(e.comp);
                    if(!si(ady[e.comp])||ady[e.comp.back()!=si(ady))ady[e.comp].pb(si(ady));
                }
                sort(all(adycomps));
                erase(unique(all(adycomps)),adycomps.end());
                ady.pb(adycomps);
                arpoints.pb(true);
            }
        }
    }
}

int main() {
	fastio;
	
    int n,e;
    cin >> n >> e;

    forn(i,e){
        int u,v;
        cin >> u >> v;
        comp.addEdge(u,v);
    }



	
	return 0;
}

