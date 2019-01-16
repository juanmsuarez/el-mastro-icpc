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

const int N = 800+10, INF = 1e9;
const double EPS = 1e-6;
vector<pair<int, double>> adj[N];
int n;
double dist[N];

bool relax() {
    bool relaxed = false;
    forn(u, n) for (auto e : adj[u]) {
        int v; double d; tie(v, d) = e;

        if (dist[u] + d > dist[v] + EPS) {
            dist[v] = dist[u] + d;
            relaxed = true;
        }
    }
    return relaxed;
}

int main() {
	fastio;
	
    int m; cin >> n >> m;
    while (m--) {
        int u, v; double c; cin >> u >> v >> c; u--, v--;
        adj[u].pb(v, log(c));
    }    

    forn(u, n) adj[n].pb(u, 0); 
    fill(dist, dist+n, -INF);
    dist[n] = 0;
    n++;

    forn(_, n-1) relax();

    cout << (relax() ? "inadmissible" : "admissible") << endl;
	
	return 0;
}
