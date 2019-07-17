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
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;

const int N = 2e5;
int e, memo[N];
vi adj[N];
char name[N];

bool can(int u) {
    if (u == e) return true;

    int &res = memo[u];
    if (res != -1) return res;
    res = false;

    for (int v : adj[u])
        if (can(v)) {
            res = true;
            break;
        }

    return res;
}

void build(int u) {
    while (u != e) {
        cout << name[u];
        for (int v : adj[u]) {
            if (can(v)) {
                u = v;
                break;
            }
        }
    }
    cout << name[u] << endl;
}

int main(){
        fastio;
    
        // input
        int n, m; cin >> n >> m;
        forn(u, n) cin >> name[u];
        while (m--) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v);
        } 
        int s; cin >> s >> e; s--, e--;

        // sort edges
        forn(u, n) sort(all(adj[u]), [](int v, int w) { return name[v] < name[w]; });

        // work 
        fill(memo, memo+n, -1);
        if (can(s)) build(s);
        else cout << "No way" << endl;

        return 0; 
}
