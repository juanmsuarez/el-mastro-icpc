#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforn(i, n) for (int i = (int)n-1; i >= 0; i--)
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;
using edge = tuple<int, int, int>;

const int INF = INT_MAX;

struct UF {
    vi p, s;
    UF(int n) { p.resize(n), iota(all(p), 0), s.assign(n, 1); }
    int find(int i) {
        while (p[i] != i) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool con(int x, int y) { return find(x) == find(y); }
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if (con(x, y)) return false;

        if (s[x] < s[y]) p[x] = y, s[y] += s[x];
        else p[y] = x, s[x] += s[y];

        return true;
    }
};

int main(){
    fastio; 

    int t; cin >> t;
    while (t--) {
        int n, m, s, e; cin >> n >> m >> s >> e;
        vector<edge> edges(m);
        for (auto &ed : edges) {
            int u, v, w; cin >> u >> v >> w;
            ed = make_tuple(w, u, v);
        }

        int ans = INF;
        sort(all(edges));
        forn(i, m) {
            int wmx, u, v; tie(wmx, u, v) = edges[i];

            UF uf(n);

            uf.join(u, v);
            if (uf.con(s, e)) ans = min(ans, 0);
            dforn(j, i) {
                int wmn; tie(wmn, u, v) = edges[j];

                uf.join(u, v);
                if (uf.con(s, e)) { ans = min(ans, wmx - wmn); break; }
            } 
        }

        if (ans == INF) cout << "NO PATH" << endl;
        else cout << ans << endl;
    }        

    return 0; 
}
