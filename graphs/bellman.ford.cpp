vector<ii> G[MAX_N];//ady. list with pairs (weight, dst)
int dist[MAX_N];
void bford(int src){//O(VE)
	dist[src]=0;
	forn(i, N-1) forn(j, N) if(dist[j]!=INF) for(auto u: G[j])
		dist[u.second]=min(dist[u.second], dist[j]+u.first);
}

bool hasNegCycle(){
	forn(j, N) if(dist[j]!=INF) for(auto u: G[j])
		if(dist[u.second]>dist[j]+u.first) return true;
	//inside if: all points reachable from u.snd will have -INF distance(do bfs)
	return false;
}
