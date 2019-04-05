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
using vii = vector<pii>;

const int N = 5e5;
int n, deg[N], par[N];
bool tree, seen[N], out[N];
vi nodes, adj[N], del[N];
vii res;

void comp(int u, int p = -1) {
    seen[u] = true;
    nodes.pb(u);

    for (int v : adj[u])
        if (!seen[v]) comp(v, u);
        else if (v != p) tree = false;
}

void solveTree() {
    for (int u : nodes) if (deg[u] == 1) res.pb(u, par[u]);
}

void solveCycle() {
    queue<int> q;
    int cnt = 0;
    for (int u : nodes) if (deg[u] == 1) q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (deg[u] == 0) continue;
        out[u] = true;

        int p = par[u];
        deg[p]--; par[p] ^= u;
        del[p].pb(u);
        if (deg[p] == 1) q.push(p);

        cnt++;
    }

    for (int u : nodes) if (!out[u])
        for (int v : del[u])
            res.pb(u, v);
}

int main() {
	fastio;
	
    int m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
        deg[u]++, deg[v]++;
        par[u] ^= v, par[v] ^= u;
    }

    forn(u, n) 
        if (!seen[u]) {
            nodes.clear(); tree = true;
            comp(u);
            if (tree) solveTree();
            else solveCycle();
        }

    sort(all(res));
    cout << si(res) << endl;
    for (auto [u, v] : res) cout << u+1 << ' ' << v+1 << endl;
	
	return 0;
}
