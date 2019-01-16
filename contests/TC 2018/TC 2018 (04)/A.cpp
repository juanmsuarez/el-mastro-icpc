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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXN =100+10;
vi adj[MAXN];
vector<bool> vis;

pair<int,bool> dfs(int u,int prev){
    vis[u]=true;
    pair<int,bool>res={1,false};
    for(auto v:adj[u]){
        if(v!=prev){
            if(vis[v]) res.second=true;
            else{
                pair<int,bool> s=dfs(v,u);
                res.first+=s.first;
                res.second|=s.second;
            }
        }
    }
    return res;
}

int main() {
    fastio;

    int n,m;
    cin >> n >> m;

    forn(i,m){
        int u,v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis = vector<bool>(n,false);
    int cant=0;
    int res=0;
    forn(u,n){
        if(!vis[u]){
            pair<int,bool> s = dfs(u,-1);
            if(s.second && s.first%2)s.first--;
            cant+=s.first;
        }
    }
    res= n-cant + (cant%2);
    D(cant);

    cout << res << endl;
    return 0;
}
