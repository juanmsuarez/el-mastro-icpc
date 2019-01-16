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
typedef tuple<int,int,int> edge;

map<string, int> h;
int cnt = 0;
int get(string s) {
    if (h.count(s)) return h[s];
    return h[s] = cnt++;
}

const int MAXN = 1e4+10, INF = 1e9;
const pii neutro = {INF, INF};
pii memo[MAXN];
vector<edge> adj[MAXN];
int k[MAXN];

pii cost(int u) {
    if (adj[u].empty()) return {0, 0}; 

    pii &res = memo[u];
    if (res != neutro) return res;

    for (auto e : adj[u]) {
        int v, c, p;
        tie(v, c, p) = e;

        pii nxt = cost(v);

        res = min(res, {nxt.first + c, nxt.second - p});
    }

    return res;
}

int main() {
    fastio;

    int budget, m;
    cin >> budget >> m;

    forn(_, m) {
        string _a, _b, _x; int c, p;
        cin >> _a >> _b >> _x >> c >> p;

        int a = get(_a), b = get(_b);
        //cerr << _a << ' ' << a << ' ' << _b << ' ' << b << endl;
        adj[a].pb(b, c, p);
    }

    int n = cnt;

    fill(memo, memo+n, neutro);

    forn(u, n) {
        pii x = cost(u);
        int c = x.first, p = -x.second;
        //cerr << u << ' ' << c << ' ' << p << endl;

        dforsn(b, c, budget+1)
            k[b] = max(k[b], k[b-c] + p);
    }

    int best = 0, mx = 0;
    forn(b, budget+1)
        if (k[b] > mx) {
            mx = k[b];
            best = b;
        }

    cout << mx << endl << best << endl;

    return 0;
}
