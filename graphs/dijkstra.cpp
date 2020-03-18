const ll N = 2e5, INF = 1e18;
typedef pair<ll,int> pli;
ll dist[N]; int par[N]; 
vector<pii> g[N];
bool seen[N];

ll dijkstra(int n, int s=0, int t=-1) { // O(E lg V)
    forn(i, n) dist[i] = INF, seen[i] = 0, par[i] = -1;
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.emplace(0, s), dist[s] = 0;

	while (!q.empty()){
		int u = q.top().snd; q.pop();
        if (seen[u]) continue;
        seen[u] = true;
		if (u == t) break;
		for (auto &e : g[u]) {
            int v, w; tie(v, w) = e;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				par[v] = u;
				q.emplace(dist[v], v);	
            }
        }
	}
	return t != -1 ? dist[t] : 0;
}

// Path generator:
vi path;
if (dist[t] != INF) {
    for (int u = t; u != -1; u = par[u]) path.pb(u);
    reverse(all(path));
}
