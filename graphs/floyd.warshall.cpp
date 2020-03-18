// if i != j, g[i][j] = weight of edge (i,j) or INF, else g[i][i] = 0
// For multigraphs: remember to keep the shortest direct paths
const int INF = 1e9, N = 200;
int g[N][N];
void floyd_warshall(int n) { // O(n^3)
    forn(k, n) 
        forn(i, n) if (g[i][k] != INF) 
            forn(j, n) if (g[k][j] != INF)
    	        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

bool inNegCycle(int u) { return g[u][u] < 0; }

// Checks if there's a negative cycle in path from a to b (precomputable):
bool hasNegCycle(int n, int a, int b) {
	forn(i, n) if (g[i][i] < 0 && g[a][i] != INF && g[i][b] != INF)
		return true;
	return false;
}
