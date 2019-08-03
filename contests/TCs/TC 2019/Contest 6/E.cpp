#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
using vi = vector<int>;


vector<vi> adj;
vector<bool> vis;

int dfs(int u){
    vis[u]=true;
    int cant  =1;
    for(int v:adj[u]){
        if(!vis[v])cant+=dfs(v);
    }
    return cant;

}

int main(){

    int n,m;
    cin >> n >> m;

    adj = vector<vi>(n);

    forn(i,m){
        int u,v;
        cin >> u >> v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }

    vis = vector<bool>(n,false);
    if(m == n-1 &&dfs(0)==n)cout << "YES" << endl;
    else cout << "NO" << endl;



}
