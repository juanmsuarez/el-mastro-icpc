#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;



typedef pair<bool,tint> term;
typedef term nodo; 
typedef pair<term,term> eje; 
typedef pair<term,term> ecu; 

term nega(term t) { return term(!t.first, t.second); }


list < nodo > fs;
bool noVs[20000 + 10][2];
vector<nodo> g[20000+10][2], gt[20000+10][2];
set<nodo> vert;

void addEje(eje e) {
    g[e.first.first][e.first.second].pb(e.second);
    gt[e.second.first][e.second.first].pb(e.first);
    vert.insert(e.first);
    vert.insert(e.second);

}
void addEcu(ecu e) {
    addEje(eje(nega(e.first), e.second));
    addEje(eje(nega(e.second), e.first));

}
void dfs(nodo ini, vector< nodo > & mEn) {
    mEn.pb(ini);
    noVs[ini.first][ini.second] = false;
    for (int i = 0; i < si(g[ini.first][ini.second]); i++){
		nodo v = g[ini.first][ini.second][i];
        if (noVs[v.first][v.second]) dfs( v, mEn);
        }
    
    fs.push_front(ini);
}
void iniNoVs() {
    for (nodo u : vert) noVs[u.first][u.second] = false;
}
void calcFs() {
    vector< nodo > dummy;
    fs.clear();
    iniNoVs();
    for (nodo u : vert)
		if (noVs[u.first][u.second])
			dfs(u, dummy);

 
}
list < vector < nodo > > comps;
void compCon() {
    iniNoVs();
    comps.clear();
    for (nodo f : fs)
        if (noVs[f.first][f.second]) {
            vector < nodo > comp;
            dfs(f, comp);
            comps.pb(comp);
        }
    
}
bool satisf() {
    for (auto c : comps ) {
        for (auto t : c  ) {
            if (noVs[(nega( t)).first][(nega(  t)).second]) return false;
        }
    }
    return true;
}
bool resolver() {
    calcFs();
    compCon();
    return satisf();
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	int n, m;
	cin >> n >> m;
	
	iniNoVs();
	
	forn(i, m) {
		char ca, cb;
		int a, b;
		cin >> ca >> a >> cb >> b;
		ecu e = mp(mp(ca == '+', a),mp(cb == '+', b));
		addEcu(e);
	}
	
	
	cout << resolver() << endl;

	return 0;
}
