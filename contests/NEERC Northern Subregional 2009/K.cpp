#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

struct Kosaraju {
  static const int default_sz = 1e5+10;
  int n;
  vector<vi> G, revG, C, ady; // ady is the condensed graph
  vector<int> used, where;
  Kosaraju(int sz = default_sz){
    n = sz;
    G.assign(sz, vector<int>());
    revG.assign(sz, vector<int>());
    used.assign(sz, 0);
    where.assign(sz, -1);
  }
  void addEdge(int a, int b){ G[a].pb(b); revG[b].pb(a); }
  void dfsNormal(vector<int> &F, int v){
    used[v] = true;
    for (int u : G[v]) if(!used[u])
      dfsNormal(F, u);
    F.pb(v);
  }
  void dfsRev(vector<int> &F, int v){
    used[v] = true;
    for (int u : revG[v]) if(!used[u])
      dfsRev(F, u);
    F.pb(v);
  }
  void build(){
    vector<int> T;
    fill(all(used), 0);
    forn(i, n) if(!used[i]) dfsNormal(T, i);
    reverse(all(T));
    fill(all(used), 0);
    for (int u : T) 
        if(!used[u]){
          vector<int> F;
          dfsRev(F, u);
          for (int v : F) where[v] = si(C);
          C.pb(F);
        }
    ady.resize(si(C)); // Create edges between condensed nodes
    forn(u, n) for(int v : G[u]){
      if(where[u] != where[v]){
        ady[where[u]].pb(where[v]);
      }
    }
    forn(v, si(C)){
      sort(all(ady[v]));
      ady[v].erase(unique(all(ady[v])), ady[v].end());
    }
  }
};

const int MAXN = 10000+10;

set<int> contains[50];
vi adj[MAXN];
vector<bool> compvalid, viscomp;
Kosaraju kosa;

bool dfsvalid(int c){
    if(viscomp[c])return compvalid[c];
    if(!compvalid[c])return false;
    viscomp[c]=true;
    for(int vc:kosa.ady[c]){
        if(dfsvalid(vc)){
            return compvalid[c] =false;
        }
    }
    return true;
}

vector<bool> vis,start;

void dfs(int u,int x){
    vis[u]=true;
    start[u]=true;
    for(int v:kosa.revG[u]){
        if(!vis[v] &&contains[x].count(v))dfs(v,x);
    }
}

int main() {
	fastio;

    freopen("kripke.in","r",stdin);
    freopen("kripke.out","w",stdout);
	
	int n,m,k;
    cin >> n >> m >> k;

    char l;
    forn(i,n){
        int c;
        cin >> c;
        forn(_,c){
            cin >> l;
            contains[l-'a'].insert(i);
        }
    }


    kosa= Kosaraju(n);
    forn(i,m){
        int u,v;
        cin >> u >> v;
        adj[u-1].pb(v-1);
        kosa.addEdge(u-1,v-1);
    }
    kosa.build();

    compvalid = vector<bool>(si(kosa.ady),true);
    viscomp = vector<bool>(si(kosa.ady),false);

    string s;
    cin >>s;
    int x = s[2] - 'a';
    int y = s[7] - 'a';
    forn(i,n){
        if(contains[y].count(i)==0)compvalid[kosa.where[i]]=false;
    }
    forn(i,n){
        if(compvalid[kosa.where[i]]&&!viscomp[kosa.where[i]]){
            dfsvalid(kosa.where[i]);
        }
    }

    vi res;
    vis = vector<bool>(n);
    start = vector<bool>(n);
    forn(i,n){
        if(compvalid[kosa.where[i]])dfs(i,x);
    }
    forn(i,n){
        if(start[i])res.pb(i+1);
    }

    cout << si(res) <<endl;


    forn(i,si(res)){
        cout << res[i]  << endl;
    }

	return 0;
}

