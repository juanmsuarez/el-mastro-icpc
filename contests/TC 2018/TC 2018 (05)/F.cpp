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
int c[MAXN];
bool vis[MAXN];
vi adj[MAXN];

int go(int u) {
    vis[u] = true;
    int ans = c[u];

    for (int v : adj[u]) 
        if (!vis[v])
            ans = min(ans, go(v));

    return ans;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    forn(i, n) cin >> c[i];
    forn(_, m) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u); 
    }

    ll ans = 0;
    forn(u, n)
        if (!vis[u])
            ans += go(u);

    cout << ans << endl;

    return 0;
}
