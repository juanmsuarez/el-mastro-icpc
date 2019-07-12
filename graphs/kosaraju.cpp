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

struct Kosaraju {
  static const int default_sz = 1e5+10;
  int n;
  vector<vi> G, revG, C, ady; // ady is the condensed graph
  vi used, where;
  Kosaraju(int sz = default_sz){
    n = sz;
    G.assign(sz, vi());
    revG.assign(sz, vi());
    used.assign(sz, 0);
    where.assign(sz, -1);
  }
  void addEdge(int a, int b){ G[a].pb(b); revG[b].pb(a); }
  void dfsNormal(vi &F, int u){
    used[u] = true;
    for (int v : G[u]) if(!used[v])
      dfsNormal(F, v);
    F.pb(u);
  }
  void dfsRev(vi &F, int u){
    used[u] = true;
    for (int v : revG[u]) if(!used[v])
      dfsRev(F, v);
    F.pb(u);
  }
  void build(){
    vi T;
    fill(all(used), 0);
    forn(i, n) if(!used[i]) dfsNormal(T, i);
    reverse(all(T));
    fill(all(used), 0);
    for (int u : T) 
        if(!used[u]){
          vi F;
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
    forn(u, si(C)){
      sort(all(ady[u]));
      ady[u].erase(unique(all(ady[u])), ady[u].end());
    }
  }
};

