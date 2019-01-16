#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
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
typedef long long int tint;

const int MAXN = 500+10, INF = 1e9;
int dist[MAXN][MAXN];
map<string, int> m;
vi ans, adj[MAXN];
bool vis[MAXN];
string names[MAXN];

void go(int u, int dest) {
    //cerr << "de " << names[u] << " a " << names[dest] << endl;
    while (u != dest) {
        ans.pb(u);
        for (int v : adj[u])
            if (dist[u][dest] == dist[v][dest] + 1) {
                u = v;
                break;
            }
    }
}

int main() {
    fastio;

    int n;
    cin >> n;
    forn(i, n) {
        cin >> names[i];

        m[names[i]] = i;
    }

    fill(dist[0], dist[MAXN], INF);
    forn(u, n) dist[u][u] = 0;

    forn(u, n) {
        string _; cin >> _;
        int k; 
        cin >> k;
        //cerr << "vecinos " << names[u] << endl;
        forn(j, k) {
            cin >> _;
            string s; 
            bool cont = true;
            do {
                cin >> s;
                if (s.back() == ',')
                    s.pop_back();
                else 
                    cont = false;

                //cerr << s << endl;
                int v = m[s];
                dist[u][v] = 1;
                adj[u].pb(v);

                if (u == v) {
                    cout << s << endl;
                    return 0;
                }
            }
            while (cont);
        }
    }

    forn(k, n) forn(i, n) forn(j, n) 
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int mn = INF, S, T;
    forn(u, n) forn(v, n)
        if (u != v && dist[u][v] + dist[v][u] < mn) {
            mn = dist[u][v] + dist[v][u];
            S = u, T = v;
        }

    if (mn == INF) cout << "SHIP IT" << endl;
    else {
        go(S, T);
        fill(vis, vis+MAXN, false);
        go(T, S);

        forn(i, si(ans)) {
            if (i) cout << ' ';
            cout << names[ans[i]];
        }
        cout << endl;
    }

    return 0;
}
