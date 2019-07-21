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

const int INF = 1e9, N = 1e5;

struct edge {
    int u, v, w, ind;
    edge(int _u, int _v, int _w, int _ind) : u(_u), v(_v), w(_w), ind(_ind) {}
    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

vector<edge> edges;
int n, t;
vi adj[N];
int ts[N];
enum color {WHITE, BLACK, GREY};
color col[N];

void build(int k) {
    forn(u, n) adj[u].clear();    

    for (auto [u, v, w, _] : edges) if (w > k) adj[u].pb(v);
}

void topo(int u) {
    for (int v : adj[u]) if (ts[v] == -1)
        topo(v);

    ts[u] = t++;
}

void ans(int k) {
    build(k);
    t = 0;
    forn(u, n) ts[u] = -1;

    forn(u, n) if (ts[u] == -1) topo(u);

    vi rev;
    for (auto [u, v, w, ind] : edges) if (w <= k)
        if (ts[u] < ts[v])
            rev.pb(ind);

    cout << k << ' ' << si(rev) << endl;
    forn(i, si(rev)) cout << rev[i]+1 << " \n"[i==si(rev)-1];
    exit(0);
}

bool cycle(int u) {
    col[u] = GREY;

    bool ans = false;
    for (int v : adj[u])
        if (col[v] == GREY) ans = true;
        else if (col[v] == WHITE && cycle(v)) ans = true;

    col[u] = BLACK;
    return ans;
}

bool can(int k) {
    build(k); 
    forn(u, n) col[u] = WHITE;

    forn(u, n) if (col[u] == WHITE && cycle(u)) return false;
    return true;
}

int main() {
	fastio;
	
    int m; cin >> n >> m;
    forn(i, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        edges.pb(u, v, w, i);
    }

    sort(all(edges));

    int lo = 0, hi = INF;
    if (can(lo)) ans(lo);
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (can(mid)) hi = mid;
        else lo = mid;
    }

    ans(hi);
	
	return 0;
}
