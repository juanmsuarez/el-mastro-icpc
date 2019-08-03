#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl;
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (int)(n-1); i >= (int) s;i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb emplace_back
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fst first
#define snd second
#define hash _hash
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;

const int N = 2e5, K = 20, H = 2;

mt19937 rng;
struct Hashing {
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

    int pot[K];
    Hashing() { 
        randomize(); 

        pot[0] = 1, pot[1] = mul; 
        forsn(i, 2, K) pot[i] = (ll)pot[i-1]*pot[i-1]%mod;
    }
} h[H];

struct Hash {
    int val[H], len;
    Hash() {}
    Hash(char c) : len(1) { forn(i, H) val[i] = c; }
    Hash operator + (Hash &o) { 
        Hash res;
        forn(i, H) res.val[i] = ((ll)val[i] * h[i].pot[o.len] + o.val[i]) % h[i].mod; 
        res.len = len+1;
        return res;
    }
    bool operator == (Hash &o) {
        forn(i, H) if (val[i] != o.val[i]) return false;
        return true;
    }
};

vi adj[N], adjr[N];
Hash hash_pref[N+1][K];
int succ[N+1][K], outdeg[N];
char name[N];
bool can[N];

int main(){
    fastio;

    // input
    int n, m; cin >> n >> m;
    forn(u, n) cin >> name[u];
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adjr[v].pb(u);
        outdeg[u]++;
    } 
    int s, e; cin >> s >> e; s--, e--;

    vi order;
    queue<int> q;
    forn(u, n) if (outdeg[u] == 0) q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adjr[u]) {
            outdeg[v]--;
            if (outdeg[v] == 0) q.push(v);
        }
        order.pb(u);
    }

    forn(k, K) succ[n][k] = n;
    can[e] = true;
    for (int u : order) {
        int best = n;

        auto better = [n](int u, int v) {
            if (v == n) return true;
            dforn(k, K) if (hash_pref[u][k] == hash_pref[v][k]) u = succ[u][k], v = succ[v][k];
            return name[u] < name[v];
        };

        for (int v : adj[u]) if (can[v]) {
            if (better(v, best))
                best = v;
        }

        if (best != n) can[u] = true;

        succ[u][0] = best;
        forsn(k, 1, K) succ[u][k] = succ[succ[u][k-1]][k-1];

        hash_pref[u][0] = name[u];
        forsn(k, 1, K) hash_pref[u][k] = hash_pref[u][k-1] + hash_pref[succ[u][k-1]][k-1];
    }

    if (!can[s]) cout << "No way" << endl;
    else {
        while (s != e) {
            cout << name[s];
            s = succ[s][0];
        }
        cout << name[s] << endl;
    }

    return 0; 
}
