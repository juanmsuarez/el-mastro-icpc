#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define sz(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
#define snd second
#define fst first
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

#define INF 1e9
int n;
#define MAX_V 1000+10
vector<pii> G[MAX_V];
//To add an edge use
#define add(a, b, w) G[a].pb(make_pair(w, b))
ll dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	vector<ll> dist(n, INF); 
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		pii p = Q.top(); Q.pop();
		if(p.snd == t) break;
		for(pii it : G[p.snd])
			if(dist[p.snd]+it.first < dist[it.snd]){
				dist[it.snd] = dist[p.snd] + it.fst;
				Q.push(make_pair(dist[it.snd], it.snd));	}
	}
	return dist[t];
}

struct edge{
    int v,a,b;
    edge(int v,int a,int b):v(v),a(a),b(b){}
};

vector<edge> adj[MAX_V];
const int MAXT=24*60;

int main() {
    fastio;
    
    int m;
    while(cin >> n >> m){
        forn(i,m){
            int u,v,a,b;
            cin >> u >> v >> a>>b;
            u--;
            v--;
            adj[u].pb(v,a,b);
            adj[v].pb(u,a,b);
        }
        forn(i,n){
            forn(j,sz(adj[i])){
                G[i].pb(adj[i][j].v,adj[i][j].b);
            }
        }
        ll res = dijkstra(0,n-1);
        forsn(t,1,MAXT+1){
            forn(i,n){
                forn(j,sz(adj[i])){
                    G[i][j].snd=(adj[i][j].a*t+adj[i][j].b);
                }
            }
            res = min(res,dijkstra(0,n-1));
        }
    }

    return 0;
}
