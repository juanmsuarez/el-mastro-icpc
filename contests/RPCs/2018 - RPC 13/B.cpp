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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 3e5+10;

vi tokens;
bitset<MAXN>vis;

vi adj[MAXN];

ll dfs(int u,ll bm){
    vis[u]=true;
    if(!(tokens[u]&bm))return 0;
    ll sum=1;
    for(int v:adj[u]){
        if(!vis[v])sum+=dfs(v,bm);
    }
    return sum;
}

int main() {
	fastio;
	
	int n;
    cin >> n;

    tokens = vi(n);
    for(int &a:tokens)cin >> a;
    for(int a:tokens)cerr << a << " ";
    cerr << endl;

    forn(_,n-1){
        int a,b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll res =0;
    forn(i,20){
        ll bm = 1<<i;
        vis.reset();

        forn(u,n){
            if(!vis[u]){
                ll cant =dfs(u,bm);
                //cerr << bm << " " << u << " " << cant<< endl;
                if(cant)res+= bm*(cant+cant*(cant-1ll)/2ll);
            }
        }
    }

    cout << res << endl;
	
	return 0;
}
