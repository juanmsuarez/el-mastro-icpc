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

const int N = 1e5, S = 100;
const int LOGN=20;

mt19937 rng;
struct basicHashing {
    int mod, mul;

    bool prime(int n) { 
        for (int d = 2; d*d <= n; d++) if (n%d == 0) return false;
        return true;
    }

    void randomize() {
        rng.seed(chrono::steady_clock::now().time_since_epoch().count());
        mod = uniform_int_distribution<>(0, (int) 5e8)(rng) + 1e9;
        while (!prime(mod)) mod++;
        mul = uniform_int_distribution<>(2,mod-2)(rng);
    }

    basicHashing() { init(); randomize(); }

    vi h, pot;
    void init() {
        h.resize(1), pot.resize(1);
        h[0] = 0, pot[0] = 1;
    }

    void process(const string &s) {
        init();
        h.resize(si(s)+1);
        pot.resize(si(s)+1);
        forn(i,si(s)) h[i+1] = (((ll)h[i] * mul) + s[i]) % mod;
        forn(i,si(s)) pot[i+1] = (ll)pot[i] * mul % mod;
    }

    int hash(int i, int j) {
        int res = h[j] - (ll)h[i] * pot[j-i] % mod;
        if (res < 0) res += mod;
        return res;
    }

    int hash(const string &s) {
        int res = 0;
        for (char c : s) res = ((ll)res * mul + c) % mod;
        return res;
    }

    void push(char c) {
        h.pb(((ll)h.back() * mul + c) % mod);
        pot.pb((ll)pot.back() * mul % mod);
    }

    void pop() {
        h.pop_back(), pot.pop_back();
    }
};

struct hashing {
    basicHashing h1, h2;

    void process(const string &s) {
        h1.process(s), h2.process(s);
    }

    void init() {
        h1.init(), h2.init();
    }

    ll hash(int i, int j) {
        return ((ll)h1.hash(i, j)<<32)+h2.hash(i, j);
    }

    ll hash(const string &s) {
        return ((ll)h1.hash(s)<<32)+h2.hash(s);
    }

    void push(char c) {
        h1.push(c), h2.push(c);
    }

    void pop() {
        h1.pop(), h2.pop();
    }
} h;

struct Query {
    int op, ind; ll hash;
    Query(int _op, int _ind, ll _hash) : op(_op), ind(_ind), hash(_hash) {}
};

vector<pair<int, char>> adj[N];

//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int f[N][LOGN], L[N]; //INICIALIZAR N!!!!!!!!!!!!!!
char fch[N];
//call before build:
void dfs(int u=0, int fa=-1, char fc=0, int lvl=0){ // generate required data
	f[u][0]=fa, fch[u]=fc, L[u]=lvl;
	for (auto [v, c] : adj[u]) if (v != fa) dfs(v, u, c, lvl+1); 
}
void build(){//f[i][0] must be filled previously, O(nlgn)
	forn(k, LOGN-1) forn(i, N) if (f[i][k]!=-1) f[i][k+1]=f[f[i][k]][k];
}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
	if (!d) return a;
	dforsn(i, 0, lg(L[a])+1) if (1<<i<=d) a=f[a][i], d-=1<<i;
    return a;
}
int lca(int a, int b){//O(lgn)
	if (L[a]<L[b]) swap(a, b);
	a = climb(a, L[a]-L[b]);
	if (a==b) return a;
	dforsn(i, 0, lg(L[a])+1) if (f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return f[a][0]; 
}
int dist(int a, int b) {//returns distance between nodes
	return L[a]+L[b]-2*L[lca(a, b)];
}

int ans[N];
vector<Query> queries[N];
unordered_map<ll, int> active;

void go(int u = 0, int p = -1) {
    int sz = L[u];
    forsn(k, 1, min(sz, S)+1) {
        ll hash = h.hash(sz-k, sz);
        if (active.count(hash)) active[hash]++;
    }

    for (auto [op, ind, hash] : queries[u])
        ans[ind] += op*active[hash];

    for (auto [v, c] : adj[u]) if (v != p) {
        h.push(c);
        go(v, u); 
        h.pop();
    }

    forsn(k, 1, min(sz, S)+1) {
        ll hash = h.hash(sz-k, sz);
        if (active.count(hash)) active[hash]--;
    }
}

int main() {
	fastio;

    int n; cin >> n;    
    forn(_, n-1) {
        int u, v; char c; cin >> u >> v >> c; u--, v--;
        adj[u].pb(v, c);
        adj[v].pb(u, c);
    }

    dfs();
    build();

    int qs; cin >> qs;
    forn(q, qs) {
        int u, v; string s; cin >> u >> v >> s; u--, v--;
        int m = si(s);

        //cerr << "query " << u+1 << ' ' << v+1 << ' ' << s << endl;

        int w = lca(u, v);
        ll y = h.hash(s);
        reverse(all(s));
        ll yr = h.hash(s);

        active[y] = 0;
        active[yr] = 0;

        queries[u].pb(1, q, yr);
        queries[v].pb(1, q, y);

        u = climb(u, max(0, L[u] - (L[w] + m - 1)));
        v = climb(v, max(0, L[v] - (L[w] + m - 1)));
        //cerr << "subo " << u+1 << ' ' << v+1 << endl;
        queries[u].pb(-1, q, yr);
        queries[v].pb(-1, q, y);

        if (w == u || w == v) continue;

        string t;
        while (u != w) {
            t += fch[u];
            u = f[u][0];
        }
        string temp;
        while (v != w) {
            temp += fch[v];
            v = f[v][0];
        }
        reverse(all(temp));
        t += temp;

        //cerr << "short path " << u << ' ' << v << ' ' << t << endl;
       
        h.process(t);
        forn(i, si(t) - m + 1) {
            ll x = h.hash(i, i + m);
            if (x == y) ans[q]++;
        }  
    }

    h.init();
    go();

    forn(i, qs) cout << ans[i] << endl; 
	
	return 0;
}
