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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN = 200+10, MAXB = 1e4+10;
vi adj[MAXN];
int d, p, r, b;
int costInd[MAXN], costComp[MAXN], 
    cant[MAXN][2],
    best[2][MAXN][MAXB];
bool vis[MAXN];

void calc(int u, int cmp) {
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            calc(v, cmp);

    costComp[cmp] += costInd[u];
    cant[cmp][0] += u < d;
    cant[cmp][1] += u >= d;
}

int main() {
    fastio;

    while (cin >> d >> p >> r >> b) {
        forn(u, d+p) adj[u].clear();
        fill(vis, vis+MAXN, false);
        fill(best[0][0], best[2][0], 0);
        fill(costComp, costComp+MAXN, 0);
        fill(cant[0], cant[MAXN], 0);

        forn(i, d) cin >> costInd[i];
        forn(i, p) cin >> costInd[d+i];

        forn(_, r) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            y += d;

            adj[x].pb(y);
            adj[y].pb(x);
        }

        int cmp = 0;
        forn(u, d+p) 
            if (!vis[u])
                calc(u, cmp++);

        forn(group, 2) {
            dforsn(c, 0, cmp) {
                forn(money, b+1) {
                    int &act = best[group][c][money];
                    act = best[group][c+1][money] + cant[c][group];

                    if (costComp[c] <= money)
                        act = max(act, best[group][c+1][money-costComp[c]] 
                                        + cant[c][group^1]);
                }
            }    
        }

        cout << best[0][0][b] << ' ' << best[1][0][b] << endl;     
    }

    return 0;
}
