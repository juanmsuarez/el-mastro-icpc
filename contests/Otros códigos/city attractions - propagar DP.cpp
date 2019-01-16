#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;
typedef long long int ll;
typedef vector<pii> vii;

const int MAXN = 3e5+10, INF = 1e9;
const ppii neutro = {{-INF, -INF}, {-INF, -INF}};
vi adj[MAXN];
int a[MAXN];
ppii dp[MAXN], down[MAXN];

void upd(ppii &a, pii b) {
    if (b > a.fi && b.se != a.se.se) {
        if (b.se != a.fi.se)
            a.se = a.fi;
        a.fi = b;
    }
    else if (b > a.se && b.se != a.fi.se) {
        a.se = b;
        if (a.se > a.fi) swap(a.fi, a.se);
    }
}

void upd(ppii &a, ppii b) {
    upd(a, b.fi);
    upd(a, b.se);
}

void dec(ppii &a) {
    a.fi.fi--;
    a.se.fi--;
}

ppii precalc(int u, int p = -1) {
    ppii &res = down[u];   
    res = neutro;
   
    // calc down
    for (int v : adj[u]) 
        if (v != p) {
            ppii resv = precalc(v, u);
            upd(resv, {a[v], -v}); 
            dec(resv);

            upd(res, resv);
        }

    return res;
}

void calc(int u, int p = -1) {
    ppii &res = dp[u];

    res = neutro;
    if (p != -1) {
        upd(res, dp[p]);
        upd(res, {a[p], -p});
        dec(res);
    }
    upd(res, down[u]);

    for (int v : adj[u]) 
        if (v != p)
            calc(v, u);
}

int main() {
    fastio;

    int n;
    ll k;
    cin >> n >> k;
    forn(u, n) cin >> a[u];
    forn(_, n-1) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    precalc(0);
    calc(0);

    int u = 0;
    vi cyc;
    vector<bool> inCycle(n, false);
    while (!inCycle[u]) {
        inCycle[u] = true;
        cyc.pb(u);
        if (u != -dp[u].fi.se)
            u = -dp[u].fi.se;
        else
            u = -dp[u].se.se;
    } 
    int posCycle;
    forn(i, si(cyc))
        if (u == cyc[i])
            posCycle = i;
    if (k >= si(cyc)) {
        k -= posCycle;
        k %= si(cyc)-posCycle;
        cout << cyc[posCycle+k]+1 << endl;
    }
    else
        cout << cyc[k]+1 << endl;

    return 0;
}
