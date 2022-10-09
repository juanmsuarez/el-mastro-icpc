#include <bits/stdc++.h>
using namespace std;

#define fastio cin.sync_with_stdio(0), cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)

#define all(a) (a).begin(),(a).end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

const int N = 1e4;

stack<int> q;
vector<vi> g[N];
bool comp_isolated[N];
int n, id, comps, x;
int in_deg[N], out_deg[N];
int low[N], idx[N], comp[N];

void tarjan(int u) {
    low[u] = idx[u] = id++;
    q.push(u), comp[u] = -2;
    
    for (int v : g[u]) {
        if (idx[v] == -1 || comp[v] == -2) {
            if (idx[v] == -1) tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == idx[u]) {
        do { x = q.top(), q.pop(), comp[x] = comps; } while (x != u);
        comps++;
    }
}

int main() {
    fastio;

    int n, m; cin >> n >> m;
    memset(idx, -1, sizeof(idx));
    memset(comp, -1, sizeof(comp));

    while (m--) {
        int x, y; cin >> x >> y, x--, y--;
        g[x].pb(y);
    }

    forn(i, n) if (idx[i] == -1) tarjan(i);
    forn(i, n) comp_isolated[i] = true;

    forn(u, n) for (int v : g[u]) if (comp[v] != comp[u]) {
        comp_isolated[v] = comp_isolated[u] = false;
        in_deg[v]++, out_deg[u]++;
    }

    forn(i, n) ans += (in_deg[i] == 0) + (out_deg[i] == 0);

    int isolated_comps = 0;
    if (comps > 1) forn(i, comps) if (comp_isolated[i]) isolated_comps++;
    
    int ans = 0;
    cout << ans << endl;
    return 0;
}
