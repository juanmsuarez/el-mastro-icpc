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

const ll N=1e6+10,INF=1e18;
int n,x,t;


int TIME[N];
int COST[N];
vector<int> adj[N]; // IMPORTANTE: ver tipo arco
//To add an edge (u,v) with cost p use G[u].pb(v,p)
ll dist[N];
int dad[N];
bool seen[N];

struct node{
    int i,t;
    node(int _i,int _t):i(_i),t(_t){}

    int ind()const{
        return t*n+i;
    }
    ll time(){
        return t+TIME[i];
    }

    ll cost(){
        return COST[i];
    }

    bool operator <(const node &o)const{
        return dist[ind()]<dist[o.ind()];
    }
    bool operator >(const node &o)const{
        return o<*this;
    }
    bool operator ==(const node &o)const{
        return i==o.i&&t==o.t;
    }
};

ll dijkstra(node s={1,0}, node dest={1,x}) {//O(|E| log |V|)
    fill(dist, dist+N, INF);
    fill(dad, dad+N, -1);
    fill(seen, seen+N, false);

	priority_queue<node, vector<node>, greater<node>> pq;
	pq.emplace(s); dist[s.ind()] = 0;

	while (!pq.empty()){
		node u = pq.top();
        cerr << u.i << " " << u.t << " " << dist[u.ind()] << endl;
        int ind=u.ind(); pq.pop();

        if (seen[ind]) continue;
        seen[ind] = true;

		if (u == dest) break;

		for (auto e : adj[u.i]) {
            node v={e,t+u.time()};
            if(v.i==u.i)v.t-=t;
            if(v.t>x)continue;
            if (dist[ind] + u.cost() < dist[v.ind()]) {
				dist[v.ind()] = dist[ind] + u.cost();
				dad[v.ind()] = ind;
				pq.emplace(v);	
            }
        }
	}

	return min(INF,dist[dest.ind()]);
}


int main() {
	fastio;

    int m;
    cin >> x >>n >> m >> t;

    forn(i,m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    forn(i,n){
        adj[i+1].pb(i+1);
        int a,b;
        cin >> a >> b;
        TIME[i+1]=a;
        cost[i+1]=b;
    }

    ll d= dijkstra();
    if(d==INF) cout << "It is a trap."<< endl;
    else cout << d << endl;

	
        
	return 0;
}
