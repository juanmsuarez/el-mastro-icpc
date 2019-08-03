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

const int MAXN=1e5+10;

vi child[MAXN];
bitset<MAXN>active,vis;

bool dfs(int u){
    vis.set(u);
    for(int v:child[u]){
        if(dfs(v))return active[u]=false;
    }
    return true;
}

int main() {
	fastio;
    freopen("bureau.in","r",stdin);
    freopen("bureau.out","w",stdout);
	
	int n;
    cin >> n;
    active.set();
    vis.reset();

    forn(i,n){
        string s;int u;
        cin >> s;
        //D(s);
        if(s=="cancel"){
            cin >> u;
            //D(u);
            child[u-1].pb(i);
        }
    }
    vi res;
    forn(i,n){
        if(!vis[i])dfs(i);
        if(active[i])res.pb(i+1);
    }
    cout << si(res) << endl;
    string sp="";
    for(auto a:res){
        cout << sp << a;
        sp=" ";
    }
    cout << endl;
	return 0;
}

