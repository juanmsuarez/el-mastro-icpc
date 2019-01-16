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

const int MAXN = 1e4+10;
const int white = 0, grey = 1, black = 2;
vi adj[MAXN];
int in[MAXN], color[MAXN];
bool cycle, edge[MAXN][MAXN];

void go(int u) {
    color[u] = grey;

    for (int v : adj[u])
        if (color[v] == white)
            go(v);
        else if (color[v] == grey)
            cycle = true;

    color[u] = black;
}

int main() {
    fastio;

    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        forn(u, n) {
            in[u] = 0;
            color[u] = white;
            adj[u].clear();
            forn(v, n) edge[u][v] = false;
        }

        while (m--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            edge[u][v] = true;
            in[v]++;
        }

        cycle = false;
        forn(u, n)
            if (color[u] == white) 
                go(u);

        if (cycle) cout << "recheck hints" << endl;
        else {
            vi ans;
            bool ordered = true;
            queue<int> q;
            forn(u, n) if (in[u] == 0) q.push(u);
            while (!q.empty()) {
                if (si(q) > 1) {
                    ordered = false;
                    break;
                }

                int u = q.front(); q.pop();
                ans.pb(u);
                for (int v : adj[u]) {
                    in[v]--;
                    if (in[v] == 0)
                        q.push(v);
                }
            }

            if (!ordered) cout << "missing hints" << endl;
            else {
                forn(i, si(ans)) {
                    if (i) cout << ' ';
                    cout << ans[i]+1;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
