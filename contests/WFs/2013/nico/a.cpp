#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) (a).begin(),(a).end()
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define endl '\n'
using ll = long long;

const int MAXN = 1e6+10;

struct bus{
    int id;
    int v;
    ll s,t;
    double p;
    bus(int _v,ll _s,ll _t,double _p):v(_v),s(_s),t(_t),p(_p){}

    bool operator <(const bus &o)const{
        return s==o.s ? (t<o.t) : s<o.s;
    }
    bool operator <(const ll &o)const{
        return s<o;
    }
};

bool operator <(const ll &a,const bus &b){
    return a<b.s;
}

vector<bus> adj[MAXN];

double memo[MAXN];

double dp(int u,int cur){
    if(u==1){
        return 1;
    }
    if(cur>=si(adj[u])){
        return 0;
    }
    bus b = adj[u][cur];
    if(memo[b.id]!=-1){
        return memo[b.id];
    }
    double &res = memo[b.id] =0;
    ll time = b.s;
 
    int nxtBus = (int)(lower_bound(adj[u].begin()+cur,adj[u].end(),time+1)-adj[u].begin());
    double miss = dp(u,nxtBus);
    forsn(j,cur,nxtBus){
        b = adj[u][j]; 
        int destBus = (int)(upper_bound(all(adj[b.v]),b.t) - adj[b.v].begin());
        double act = max(dp(b.v,destBus)*b.p+(1-b.p)*miss, miss);
        res = max(res,act);
        cur++;
    }
    return res;
}

int main() {
    fastio;

    int n,m;
    ll k;
    cin >> m >> n;
    cin >> k;

    forn(i,m){
        int u,v;ll s,t;double p;
        cin >> u >> v >> s >> t >> p;
        adj[u].pb(v,s,t,p);
        adj[u].back().id=i;
    } 

    forn(i,n){
        sort(all(adj[i]));
    }
    fill(memo,memo+MAXN,-1);
    cout << fixed << setprecision(6) <<  dp(0,0) << endl;

    return 0;
}
