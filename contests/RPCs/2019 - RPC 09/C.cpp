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

const int N = 1000+10;
const ll INF = 1e9+1e6;
int pathlen,x;

vi ridelen,cost;

vi adj[N]; // IMPORTANTE: ver tipo arco
//To add an edge (u,v) with cost p use G[u].pb(v,p)
ll dist[N][N];
bool seen[N][N];

using entry = tuple<int,int,ll>;

ll dijkstra(pii s=(pii){0,ridelen[0]}, pii t=(pii){0,x}) {//O(|E| log |V|)
    fill(dist[0], dist[N], INF);
    fill(seen[0], seen[N], false);

	priority_queue<entry, vector<entry>, greater<entry>> pq;
	pq.emplace(0, s.fst, s.snd); dist[s.fst][s.snd] = 0;

	while (!pq.empty()){
		int u;ll act;
        tie(ignore, u,act) =pq.top(); pq.pop();
        //D(u);D(act);D(dist[u][act]);

        if (seen[u][act]) continue;
        seen[u][act] = true;

		if (pii(u,act) == t) break;

		for (int v : adj[u]) { 
            ll nxt = act+pathlen + ridelen[v];
			if (nxt <= x && dist[u][act] + cost[u]< dist[v][nxt]) {
				dist[v][nxt] = dist[u][act] + cost[u];
                //D(v);D(nxt);D(dist[v][nxt]);
                //D(ridelen[v]);
				pq.emplace(dist[v][nxt], v,nxt);	
            }
        }
        ll nxt = act+ ridelen[u];
        if (nxt <= x && dist[u][act] + cost[u]< dist[u][nxt]) {
            dist[u][nxt] = dist[u][act] + cost[u];
            pq.emplace(dist[u][nxt], u,nxt);	
        }

    }

    return dist[0][x]!=INF ? dist[0][x]+cost[0]: -1;
}

int main() {
    fastio;

    cin >> x;
    int n,m;
    cin >> n >> m;
    cin >> pathlen;

    forn(i,m){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ridelen = vi(n);
    cost = vi(n);
    forn(i,n){
        cin >> ridelen[i] >> cost[i];
    }

    ll res = dijkstra();
    cout << (res==-1 ? "It is a trap.":to_string(res)) << endl;

    return 0;
}

