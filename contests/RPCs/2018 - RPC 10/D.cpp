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

const int MAXN = 1e5+10, INF = 1e9+1, MOD = 1e9+7;
vector<pii> G[MAXN];
vi pre[MAXN];
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
    
    forn(u, n)
        for (pii e : G[u]) {
            int v = e.snd;
            if (dist[u]+e.fst == dist[v])
                pre[v].pb(u);
        }

    return dist[t];
}

int add(int a, int b) {
    return a+b>=MOD ? a+b-MOD : a+b;
}

int memo[MAXN];

int dp(int u) {
    if (u == 0) return 1;

    int &res = memo[u];
    if (res != -1) return res;
    res = 0;

    for (int v : pre[u])
        res = add(res, dp(v));

    return res;
}

int main() {
	fastio;

    int m;
    while (cin >> n >> m) {
        forn(u, n) G[u].clear(), pre[u].clear();

        while (m--) {
            int u, v, c; cin >> u >> v >> c;
            G[u].pb(c, v); G[v].pb(c, u);
        }

        fill(memo, memo+n, -1);
        cout << dijkstra(0, n-1) << ' '; cout << dp(n-1) << endl;
    }

	return 0;
}
