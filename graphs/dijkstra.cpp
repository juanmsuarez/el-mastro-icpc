vector<pii> adj[N]; // IMPORTANTE: ver tipo arco
//To add an edge (u,v) with cost p use G[u].pb(v,p)
ll dist[N];
int dad[N];
bool seen[N];

ll dijkstra(int s=0, int t=-1) {//O(|E| log |V|)
    fill(dist, dist+N, INF);
    fill(dad, dad+N, -1);
    fill(seen, seen+N, false);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, s); dist[s] = 0;

	while (!pq.empty()){
		int u = pq.top().snd; pq.pop();

        if (seen[u]) continue;
        seen[u] = true;

		if (u == t) break;

		for (auto e : adj[u]) {
            int v, p; tie(v, p) = e;
			if (dist[u] + p < dist[v]) {
				dist[v] = dist[u] + p;
				dad[v] = u;
				pq.emplace(dist[v], v);	
            }
        }
	}

	return t != -1 ? dist[t] : 0;
}
// path generator
if (dist[t] < INF)
    for (int u = t; u != -1; u = dad[u])
        cout << u << " \n"[u == s];
