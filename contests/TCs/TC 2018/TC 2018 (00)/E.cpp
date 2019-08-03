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
int t[MAXN];

int go(int u, int ts) {
    t[u] = ts++;

    vi tomatch;
    for (int v : adj[u])
        if (!t[v]) {
            int extra = go(v, ts+1);
            if (extra != -1)
                cout << u+1 << ' ' << v+1 << ' ' << extra+1 << endl;
            else
                tomatch.pb(v);
        }
        else if (t[v] > t[u])
            tomatch.pb(v);

    //cerr << "En: " << u << endl;

    while (si(tomatch) >= 2) {
        int v = tomatch.back(); tomatch.pop_back();
        int w = tomatch.back(); tomatch.pop_back();
        cout << v+1 << ' ' << u+1 << ' ' << w+1 << endl;
    }

    return tomatch.empty() ? -1 : tomatch.back();
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    forn(_, m) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    if (m%2 == 0) go(0, 1);
    else cout << "No solution" << endl;

    return 0;
}
