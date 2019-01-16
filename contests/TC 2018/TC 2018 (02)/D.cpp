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

const int MAXN = 2e5+10, INF = 1e9;
vector<edge> adj[MAXN];
int flow[MAXN], extra[MAXN], dest[MAXN];
bool ans[MAXN], done[MAXN], in[MAXN];

int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int u, v, f;
        cin >> u >> v >> f;
        u--; v--;
        adj[u].pb(v, f, i);
        adj[v].pb(u, f, i);

        extra[u] += f; extra[v] += f;

        dest[i] = v;
    }

    queue<int> process;
    process.push(0);

    while (!process.empty()) {
        int u = process.front(); process.pop();

        for (edge e : adj[u]) {
            int v, f, ind;
            tie(v, f, ind) = e;

            if (!done[v]) { // check
                flow[v] += f; extra[v] -= f;
                ans[ind] = dest[ind] != v;

                if (flow[v] == extra[v] && !in[v] && v != n-1) {
                    in[v] = true;
                    process.push(v);
                }
            }
        }

        done[u] = true;
    } 

    forn(i, m) cout << ans[i] << endl;

    return 0;
}
