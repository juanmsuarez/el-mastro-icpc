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

const int N = 2e3;
vi adj[N];

const int MOD = 1e9 + 7;
int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }

int ways[N];
bool reachable[N];
bool seen[N];
void dfs(int u) {
    if (u == 0) {
        reachable[u] = true;
        ways[u] = 1;
    }

    if (seen[u]) return;
    seen[u] = true;

    for (int v : adj[u]) {
        dfs(v);
        reachable[u] |= reachable[v];
        ways[u] = add(ways[u], ways[v]);
    }
}

int main() {
	fastio;
	
    int n, l; cin >> n >> l;
    forn(u, l) {
        int m; cin >> m;
        forn(_, m) {
            int v; cin >> v; v--;
            adj[v].pb(u);
        }
    }

    int total_ways = 0;
    int reachable_clients = 0;
    forsn(u, l, n) {
        dfs(u);
        reachable_clients += reachable[u];
        total_ways = add(total_ways, ways[u]);
    }

    cout << total_ways << ' ' << reachable_clients << endl;
	
	return 0;
}
