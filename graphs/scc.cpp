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

int main(){
  
  return 0;
}
