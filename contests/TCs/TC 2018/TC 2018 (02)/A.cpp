#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 1e5+10;
vi adj[MAXN];
int c[MAXN], k[MAXN], ans[MAXN];
vi qs[MAXN];

struct s {
    unordered_map<int,int> cant;
    unordered_map<int,int> fen;
    int tot;

    s() {
        tot = 0;
    }

    int size() {
        return si(cant); 
    }

    void set(int x, int y) {
        for (; x < MAXN; x += (x&-x))
            fen[x] += y;
    }

    int get(int x) {
        int r = 0;
        for (; x > 0; x -= (x&-x))
            r += fen[x];
        return r;
    }

    void update(int color, int q) {
        if (cant[color] > 0) 
            set(cant[color], -1);
        else
            tot++;

        cant[color] += q;
        set(cant[color], +1);
    }
    
    int query(int q) {
        return tot - get(q-1);
    }

    void print() {
        for (pii p : cant) {
            cerr << p.first << ' ' << p.second << endl;
            cerr << "suma hasta " << p.second << " = " << query(p.second) << endl;
        }
    }
};

s& mergeDFS(s &a, s &b) {
    if (a.size() < b.size()) swap(a,b);

    for (pii p : b.cant) {
        int color = p.first, cant = p.second;
        a.update(color, cant);
    }

    return a;
}

s& go(int u, int p = -1) {
    s &estado = *(new s());
    estado.update(c[u], 1);

    for (int v : adj[u]) {
        if (v != p) {
            s &estadov = go(v, u);
            estado = mergeDFS(estado, estadov);
        }
    } 

    for (int i : qs[u]) {
        int cant = k[i];
        ans[i] = estado.query(cant);
        //cerr << "query " << i << ' ' << ans[i] << endl;
    }

    //cerr << "Nodo " << u << endl;
    //estado.print();

    return estado;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    forn(i, n) cin >> c[i];
    forn(_, n-1) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }
    forn(i, m) {
        int u; 
        cin >> u >> k[i]; 
        u--;
        qs[u].pb(i);
    }

    go(0);

    forn(i, m) cout << ans[i] << endl;

    return 0;
}
