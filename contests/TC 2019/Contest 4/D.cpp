
#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(a) a.begin(),a.end()
#define si(a) ((int)(a).size())
#define pb emplace_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

struct Kosaraju{
    static const int default_sz = 1e5+10;
    int n;
    vector<vi> G, revG, C, ady;
    vector<bool> nulldegree;
    vi used, where;
    Kosaraju(int sz = default_sz){
        n = sz;
        G.assign(sz, vi());
        revG.assign(sz, vi());
        used.assign(sz,0);
        where.assign(sz,-1);
    }

    void addEdge(int a, int b){ 
        G[a].pb(b); revG[b].pb(a);
    }
    void dfsNormal(vi &F, int v){
        used[v] = true;
        for(int u : G[v])if(!used[u])
            dfsNormal(F,u);
        F.pb(v);
    }

    void dfsRev(vi &F, int v){
        used[v] = true;
        for(int u : revG[v])if(!used[u])
            dfsRev(F,u);
        F.pb(v);
    }

    vi build(){
        vi res;
        vi T;
        fill(all(used),0);
        forn(i,n)if(!used[i])dfsNormal(T,i);
        reverse(all(T));
        fill(all(used),0);
        for(int u : T)
            if(!used[u]){
                vi F;
                dfsRev(F,u);
                for(int v:F)where[v] = si(C);
                C.pb(F);
            }

        ady.resize(si(C));
        nulldegree = vector<bool>(si(C),true);
        forn(u,n)for(int v: G[u]){
            if(where[u] != where[v]){
                ady[where[u]].pb(where[v]);
                nulldegree[where[v]]=false;
            }
        }
        forn(v, si(C)){
            sort(all(ady[v]));
            ady[v].erase(unique(all(ady[v])), ady[v].end());
            if(nulldegree[v])res.pb(v);
        }
        return res;
    }

};

Kosaraju k;

int main(){
    fastio;

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        k = Kosaraju(n);
        forn(u,n){
            int m;
            cin >> m;
            forn(j,m){
                int v;
                cin >> v; v--;
                k.addEdge(v,u);
            } 
        } 
        vi res = k.build();
        if(si(res)>1)cout << 0 << endl;
        else cout << si(k.C[res.front()]) << endl;
        
    }

    return 0;
}
