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

vector<int> adj[20];
const int MAXK=1<<19;
ll memo[MAXK][19];

int s;
ll dp(int mask,int t){
    if(memo[mask][t]!=-1)return memo[mask][t];
    ll &res=memo[mask][t]=0;

    for(int v:adj[t]){
        if(v==s) {
            res++;
        }
        else if(!(mask&(1<<v)) && v >= s){
            res+=dp((mask|(1<<v)),v);
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
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    
    ll res=0;
    forn(i,n){
        s=i;
        fill(memo[0],memo[MAXK],-1);
        res+=dp(1<<i,i);
    }
    cout << (res-m)/2 << endl;

    return 0;
}
