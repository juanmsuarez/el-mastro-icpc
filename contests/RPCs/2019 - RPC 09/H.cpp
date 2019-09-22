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
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

vi adj[100];

pii dfs(int u,int p =-1){
    pii res = {0,u};
    for(int v:adj[u]){
        if(v!=p){
            res = max(res,dfs(v,u));
        }
    }
    res.fst++;
    return res;
}

bool has(int u,int p,int r){
    if(u==r)return true;
    bool res=false;
    for(int v:adj[u]){
        if(v!=p)res=has(v,u,r);
        if(res)return res;
    }
    return res;
}

int rad(int r){
    int v = dfs(r).snd;
    return (dfs(v).fst)/2;
}

int calc(int r,int block){
    for(int v:adj[block]){
        if(has(v,block,r))return dfs(v,block).fst;
    }
    return -1;
}


int main() {
	fastio;
	
	int n,r,h,m;
    cin >> n >> r >> h >> m;
    r--,h--,m--;

    forn(i,n-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    D(1+rad(r));
    D(calc(r,h));
    D(calc(r,m));
    cout << min(1+rad(r),min(calc(r,h),calc(r,m))) << endl;
    


	return 0;
}

