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
typedef pair<int, char> edge;

const int MAXN = 5e5+10;

vector<edge> adj[MAXN];
int m; string s;
bool vis[MAXN]; pii up[MAXN], down[MAXN], path[MAXN];

inline void upd(pii &res, pii u, pii d) {
    int ulen = u.first, nu = u.second,
        dlen = d.first, nd = d.second;
    if (ulen + dlen >= m)
        res = {nu, nd};
}

void dp(int v, int p = -1) {
    if (vis[v]) return;
    vis[v] = true;

    pii &u = up[v], &d = down[v];
    u = {0, v}; d = {0, v}; path[v] = {-1, -1};

    for (auto e : adj[v]) {
        int w = e.first; char c = e.second;
        if (w != p) {
            dp(w, v);
            pii dw = down[w], uw = up[w];

            // act solucion v
            int &ulenw = uw.first;
            if (ulenw < m && c == s[ulenw]) ulenw++;
            int &dlenw = dw.first;
            if (dlenw < m && c == s[m-(dlenw+1)]) dlenw++;

            // camino de v a prev
            upd(path[v], uw, d);
            upd(path[v], u, dw);

            u = max(u, uw);
            d = max(d, dw);
        }
    }
}

int main() {
    fastio;

    int n;
    cin >> n >> m;
    forn(_, n-1) {
        int u, v; char c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].pb(v, c);
        adj[v].pb(u, c);
    }
    cin >> s;

    dp(0);

    pii ans = {-2, -2};
    forn(u, n)
        if (path[u] != (pii){-1, -1})
            ans = path[u];
    cout << ans.first+1 << ' ' << ans.second+1 << endl;

    return 0;
}
