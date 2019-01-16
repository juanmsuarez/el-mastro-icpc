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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = 1e4+10; const ll INF = 1e18;
typedef tuple<int, int, int> edge;
vector<edge> adj[N]; // IMPORTANTE: ver tipo arco
//To add an edge (u,v) with cost p use G[u].pb(v,p)
ll dist[N];
bool seen[N];

typedef tuple<ll,int,int> node;
ll dijkstra(int s=0) {//O(|E| log |V|)
    fill(dist, dist+N, INF);
    fill(seen, seen+N, false);

	priority_queue<node, vector<node>, greater<node>> pq;
	pq.emplace(0, 0, s); dist[s] = 0;

    ll cost = 0;
	while (!pq.empty()){
		int u, c; ll d; tie(d, c, u) = pq.top(); pq.pop();

        if (seen[u]) continue;
        seen[u] = true;

        cost += c;

		for (auto e : adj[u]) {
            int v, p, nc; tie(v, p, nc) = e;
			if (dist[u] + p <= dist[v]) {
				dist[v] = dist[u] + p;
				pq.emplace(dist[v], nc, v);	
            }
        }
	}

	return cost;
}

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v, l, c; cin >> u >> v >> l >> c; u--, v--;
        adj[u].pb(v, l, c);
        adj[v].pb(u, l, c);
    }        

    cout << dijkstra() << endl;
	
    return 0;
}
