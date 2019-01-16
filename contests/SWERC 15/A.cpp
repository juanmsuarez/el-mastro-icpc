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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

const int MAXN = 5000+10;
vi adj[MAXN][2];

bitset<5010> vis;

int dfs(int u,int ind){
    vis[u]=1;
    int cant=1;
    for(int v:adj[u][ind]){
        if(!vis[v]){
            cant+=dfs(v,ind);
        }
    }
    return cant;
}

int main() {
    fastio;

    int a,b,n,m;
    cin >> a >> b >> n >>m;
    forn(i,m){
        int u,v;
        cin >> u >>v;
        adj[u][0].pb(v);
        adj[v][1].pb(u);
    }

    int resA=0,resB=0;
    forn(i,n){
        vis.reset();
        int subdag=dfs(i,0);
        if(n-subdag<a)resA++;
        if(n-subdag<b)resB++;
    }
    int resC=0;
    forn(i,n){
        vis.reset();
        int subdag=dfs(i,1);
        if(subdag>b){
            resC++;
        }
    }
    
    cout << resA << endl <<resB << endl <<resC << endl;

    return 0;
}
