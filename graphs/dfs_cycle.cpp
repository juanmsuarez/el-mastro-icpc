// DFS

// Podríamos poner el DFS que pinta nodos. ¿Para chequear ciclos en dirigidos?
// https://github.com/nicalvarez/algoritmos-acm/blob/master/v2/dfs_cycle.cpp

const int MAXN = 1e5+10;

vi adj[MAXN];
bool vis[MAXN];

void dfs(int u) {
	if (used[u]) return;
	used[u] = true;
	
	for (v : adj[u])
		dfs(v);
} 
