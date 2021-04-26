int used[MAXN], ars[MAXE], eq, n, m;
using lit = list<int>::iterator;
bool usede[MAXE];
list<int> path;
queue<lit> q;
vi g[MAXN];
int get(int v) {
	while (used[v] < si(g[v]) && usede[g[v][used[v]]]) used[v]++;
	return used[v];
}
void explore(int v, int r, lit it) {
	int ar = g[v][get(v)], u = v ^ ars[ar];
	usede[ar] = true;
	lit it2 = path.insert(it, u);
	if (u != r) explore(u, r, it2);
	if (get(v) < si(g[v])) q.push(it);
}
void euler() {
	path.pb(0), q.push(begin(path));
	while (si(q)) {
		lit it = q.front(); q.pop();
		if (used[*it] < si(g[*it])) explore(*it, *it, it);
	}
	reverse(all(path));
}
void addEdge(int u, int v, bool undirected = true) { 
    g[u].pb(eq);
    if (undirected) g[v].pb(eq);
    ars[eq++] = u ^ v;
}
