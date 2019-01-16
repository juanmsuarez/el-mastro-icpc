#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define si(a) ((int)(a).size())
#define forn(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair

const int MAXN = 1e5+10;

set<pii> lista;
vector<int> adj[MAXN];
int act[MAXN];
bool alive[MAXN];

void actualizar(int u) {
    for (int v : adj[u]) {
        if (alive[v]) {
            lista.erase(mp(act[v], v));
            act[v]--;
            lista.insert(mp(act[v], v));
        }
    }
}

int main(){
	int n, m, a, b;

    while (cin >> n >> m >> a >> b) {
        lista.clear();
        forn(u, n) adj[u].clear(), alive[u] = true;

        forn(i, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        forn(i, n) {
            lista.insert(mp(si(adj[i]), i));
            act[i] = si(adj[i]);
        }

        while (!lista.empty()) {
            if (lista.begin() -> first < a) {
                auto it = lista.begin();
                int u = it->second;

                actualizar(u);
                alive[u] = false;

                lista.erase(*it);
            }
            else if (si(lista) - lista.rbegin()->first - 1 < b) {
                auto it = lista.rbegin();
                int u = it->second;

                actualizar(u);
                alive[u] = false;

                lista.erase(*it);
            }
            else break;
        }

        cout << si(lista) << endl;
    }
			
	return 0;
}
	
