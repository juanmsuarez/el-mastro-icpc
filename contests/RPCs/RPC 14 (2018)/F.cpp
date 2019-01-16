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
typedef vector<pii> vii;

const int N = 5e3, M = 10, INF = 1e9;
int c[N], sm[N], dp[1<<M];
vi adj[N];
bool seen[N];

pii go(int u) {
    seen[u] = true;
    pii ans = {c[u], sm[u]};

    for (int v : adj[u])
        if (!seen[v]) {
            pii other = go(v);
            ans.fst += other.fst;
            ans.snd |= other.snd;
        }

    return ans;
}

int main() {
	fastio;
	
    int n, s, f;

    while (cin >> n >> s >> f) {
        forn(u, n) adj[u].clear();
        fill(seen, seen+n, false);
        fill(sm, sm+n, 0);

        forn(u, n) cin >> c[u];

        while (f--) {
            int u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }

        forn(i, s) {
            int k; cin >> k;
            while (k--) {
                int u; cin >> u;
                //cerr << u << ' ' << sm[u];
                sm[u] |= 1<<i;
                //cerr << ' ' << sm[u] << endl;
            }
        }

        vii v;
        forn(u, n) 
            if (!seen[u])
                v.pb(go(u));

        int cs = si(v);
        fill(dp, dp+(1<<s), INF);
        dp[0] = 0;

        forn(cn, cs)
            forn(m, 1<<s) {
                int nm = m | v[cn].snd;
                dp[nm] = min(dp[nm], dp[m] + v[cn].fst);
            }

        cout << dp[(1<<m)-1] << endl;
    }    
	
	return 0;
}
