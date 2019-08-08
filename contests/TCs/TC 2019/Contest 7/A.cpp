#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
using vvi = vector<vi>;
using vb = vector<bool>;
using ll = long long;

const int N = 200;

//We have a vertex representing a var and other for his negation.
//Every edge stored in G represents an implication. To add an equation of the form a||b, use addor(a, b)
//N=max cant var, n=cant var
struct SAT {
    vector<int> adj[N*2];
    //idx[i]=index assigned in the dfs
    //lw[i]=lowest index(closer from the root) reachable from i
    int lw[N*2], idx[N*2], qidx;
    stack<int> q;
    int qcmp, cmp[N*2];
    //value[cmp[i]]=valor de la variable i
    bool value[N*2+1];
    int n;

    //remember to CALL INIT!!!
    void init(int _n) {
        n = _n; 
        forn(u, 2*n) adj[u].clear();
    }

    int neg(int x) { return x >=n ? x-n : x+n; }
    void addor(int a, int b) { adj[neg(a)].pb(b), adj[neg(b)].pb(a); }

    void tjn(int v){
        lw[v]=idx[v]=++qidx;
        q.push(v), cmp[v]=-2;
        for (auto u : adj[v]){
            if (!idx[u] || cmp[u]==-2){
                if (!idx[u]) tjn(u);
                lw[v]=min(lw[v], lw[u]);
            }
        }
        if (lw[v]==idx[v]){
            int x;
            do { x=q.top(); q.pop(); cmp[x]=qcmp; } while (x!=v);
            value[qcmp]=(cmp[neg(v)]<0);
            qcmp++;
        }
    }

    bool satisf(){ //O(n)
        memset(idx, 0, sizeof(idx)), qidx=0;
        memset(cmp, -1, sizeof(cmp)), qcmp=0;
        forn(i, n){
            if (!idx[i]) tjn(i);
            if (!idx[neg(i)]) tjn(neg(i));
        }
        forn(i, n) if (cmp[i]==cmp[neg(i)]) return false;
        return true;
    }
} sat;

struct UF { // Operations take O(log*(n))
    int p[N], s[N];
    void init(int n){ iota(p, p+n, 0), fill(s, s+n, 1); }
    int find(int i){
	    while (p[i] != i) p[i] = p[p[i]], i = p[i];
	    return i;
    }
    bool connected(int x, int y){ return find(x) == find(y); }
    bool join(int x, int y){
    	x = find(x), y = find(y);
        if (connected(x, y)) return false;

    	if (s[x] < s[y]) p[x] = y, s[y] += s[x];
    	else p[y] = x, s[x] += s[y];
        return true;
    }
};

struct Edge {
    int u, v, c;
    bool inMst;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c), inMst(false) {}
    bool operator < (const Edge &o) const { return c > o.c; }
};

struct Kruskal {
    vector<int> adj[N];
    bool color[N];
    vector<Edge> edges;
    int n;
    UF uf;

    void init(int _n) {
        n = _n;

        edges.clear();
        forn(u, n) adj[u].clear(), color[u] = false;

        uf.init(n);
    }
    void addEdge(int u, int v, int c) { edges.pb(u, v, c); }

    void build() {
        sort(all(edges));

        for (auto &[u, v, _, inMst] : edges) {
            if (uf.join(u, v)) {
                inMst = true;
                adj[u].pb(v), adj[v].pb(u);
            }
        }
    }

    void dfs(int u = 0, int p = -1, bool c = false) {
        color[u] = c;

        for (int v : adj[u]) if (v != p)
            dfs(v, u, !c);
    }

    void addOddCycle() {
        dfs(); 

        for (auto &[u, v, c, inMst] : edges) 
            if (!inMst && color[u] == color[v]) {
                inMst = true;
                break;
            }
    }
} kruskal;

bool can(int n, vector<Edge> &edges, int a, int b) {
    int m = si(edges);

    sat.init(n);
    forn(i, m) {
        int u = edges[i].u, v = edges[i].v, c = edges[i].c;
        if (c > a) sat.addor(u, v), sat.addor(sat.neg(u), sat.neg(v));
        else if (c > b) sat.addor(u, v);
    }

    return sat.satisf();
}

const int INF = 2e9;
int solve(int n) {
    kruskal.init(n);
    forn(u, n-1) forsn(v, u+1, n) {
        int c; cin >> c;
        kruskal.addEdge(u, v, c);
    }

    kruskal.build();
    kruskal.addOddCycle();
    vector<Edge> &edges = kruskal.edges;

    vi weights = {0}, weightsInMst = {0};
    for (auto [u, v, c, inMst] : edges) {
        if (inMst) weightsInMst.pb(c);
        weights.pb(c);
    }

    auto compress = [](vi &v) { sort(all(v)); v.erase(unique(all(v)), v.end()); };
    compress(weights), compress(weightsInMst);
    reverse(all(weights)), reverse(all(weightsInMst));

    int ans = INF;
    for (int maxWeight : weightsInMst) {
        int lo = 0, hi = si(weights);
        while (weights[lo] > maxWeight) lo++;
        if (!can(n, edges, maxWeight, weights[lo])) break;

        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (can(n, edges, maxWeight, weights[mid])) lo = mid;
            else hi = mid;
        }

        ans = min(ans, maxWeight + weights[lo]);
    }

    return ans;
}

int main() {
	fastio;
	
    int n; 
    while (cin >> n) cout << solve(n) << endl;
	
	return 0;
}
