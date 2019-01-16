// BFS

const int N = 1e5+10, INF = 1e9;
int dist[N];
vi adj[N];

void bfs(int start, int n) {
	fill(dist, dist+n, INF);

	queue<int> q;
	
	q.push(start);
	dist[start] = 0;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int v : adj[u])
			if (dist[v] == INF) {
				q.push(v);
				dist[v] = dist[u] + 1;
			}
	}
}
