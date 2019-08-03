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
using plli = pair<ll, int>;

const int N = 1e3;
const ll INF = 1e18;

vector<pii> adj1[N], adj2[N];
ll dist[N];

ll distraela(vector<pii> adj[N], int s=0, int t=-1) {//O(|E| log |V|)
    fill(dist, dist+N, INF);
    vector<bool> seen(N);

	priority_queue<plli, vector<plli>, greater<plli>> pq;
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
				pq.emplace(dist[v], v);	
            }
        }
	}

	return t != -1 ? dist[t] : INF;
}

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t; s--, t--;
    while (m--) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj1[u].pb(v, w);
        adj1[v].pb(u, w);
    }    

    forn(u, n) {
        int mxdist, cost; cin >> mxdist >> cost;
        distraela(adj1, u); 

        forn(v, n) if (v != u && dist[v] <= mxdist) adj2[u].pb(v, cost);
    }

    ll cost = distraela(adj2, s, t);
    cout << (cost == INF ? -1 : cost) << endl;
	
	return 0;
}
