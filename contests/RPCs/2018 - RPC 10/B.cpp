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

const int MAXN = 500+10, INF = 1e9;
vector<pii> G[MAXN];
int n;
//To add an edge use
int dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	vector<int> dist(n, INF);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(si(Q)){
		pii p = Q.top(); Q.pop();
		if (p.snd == t) break;
		for (pii e : G[p.snd])
			if(dist[p.snd]+e.first < dist[e.snd]){
				dist[e.snd] = dist[p.snd] + e.fst;
				Q.push(make_pair(dist[e.snd], e.snd));	}
	}
	return dist[t];
}

int main() {
	fastio;

    cout << fixed << setprecision(2);

    int m;
    while (cin >> n >> m) {
        // clear
        forn(u, n) G[u].clear();

        int x, y; cin >> x >> y;
        
        while (m--) {
            int u, v, d; cin >> u >> v >> d; u--; v--;
            G[u].pb(d,  v); G[v].pb(d, u);
        }

        int s, t; cin >> s >> t; s--; t--;
        cout << (double)dijkstra(s, t)/(x+y) << endl;
    }

	return 0;
}
