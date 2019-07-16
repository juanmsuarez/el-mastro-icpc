struct bridge {
	struct edge {
		int u,v,comp;
		bool bridge;
	};

	int n,t,nbc;
	vi d,b,comp;
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

    //d[i]=id de la dfs
    //b[i]=lowest id reachable from i
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
};
