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

int N;
const int MAXN = 1e5+10;
const ll INF = 1e15;
vector<pii> G[MAXN];
//To add an edge (u,v) with cost p use G[u].pb(v,p)
ll dist[MAXN];
int dad[MAXN];
ll dijkstra(int s, int t=-1){//O(|E| log |V|)
	priority_queue<pii, vector<pii>, greater<pii> > pq;
    fill(dist,dist+MAXN,INF);
    fill(dad,dad+MAXN,-1);
	pq.emplace(0, s); dist[s] = 0;
	while(!pq.empty()){
		int u = pq.top().snd; pq.pop();
		if(u == t) break;
		for (auto [v,p] : G[u]) {
			if(dist[u]+p < dist[v]){
				dist[v] = dist[u] + p;
				dad[v] = u;
				pq.emplace(dist[v], v);	
            }
        }
	}
	return (t!=-1?dist[t]:0);
}
	//if(dist[t]<INF)//path generator
	//	for(int i=t; i!=-1; i=dad[i])
	//		printf("%d%c", i, (i==s?'\n':' '));

vector<ll> cost[MAXN];
int main() {
	fastio;
	
    int m;
    cin >> N >> m;
    forn(i,m){
        int a,b,l,c;
        cin >> a >> b >> l >>c;
        G[a].pb(b,l);
        G[b].pb(a,l);
        cost[a].pb(c);
        cost[b].pb(c);
    }

	
    dijkstra(1);
    ll res=0;
    forsn(u,2,N+1){
        ll best=1e9;
        D(u);
        D(dist[u]);
        forn(j,si(G[u])){
            if(dist[G[u][j].fst]+G[u][j].snd==dist[u])
                best=min(best,cost[u][j]);
        }
        res+=best;
    }

    cout << res << endl;
	
	return 0;
}

