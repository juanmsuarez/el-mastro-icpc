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

int main() {
	fastio;
    freopen("instruction.in","r",stdin);
    freopen("instruction.out","w",stdout);

    int n;
    cin >> n;
    vector<vi> adj(n+1);
    vi parent(n+1,-1),current(n+1),platform;
    map<char,int> platformID;
    vector<vi> platPath(n+1);

    forn(i,n){
        char c;int q;
        cin >> c >> q;
        parent[i+1]=q;
        adj[q].pb(i+1);
        if(c=='p'){
            platform.pb(i+1);
            char name;
            cin >> name;
            D(name);
            platformID[name]=i+1;
        }
    }
    forn(i,n+1)sort(all(adj[i]));//Lower ID by default
    for(int p:platform){//create paths to every platform
        platPath[p].pb(p);
        int u = parent[p];
        D(p);
        while(u != 0){
            D(u);
            platPath[p].pb(u);
            u=parent[u];
        }
        D(u);
        reverse(all(platPath[p]));
    }

    int m;
    cin >> m;
    vector<tuple<int,int,int>>requirements;//for each train determine all the required switch positions
    forn(i,m){
        int time;char dest;
        cin >> time >> dest;
        vi &destPath = platPath[ platformID[dest] ];
        int act = 0;
        for(int u:destPath){
            requirements.pb(time,act,u);
            act=u;
            time++;
        }
    }
    sort(all(requirements));
    vector<pii> commands;//simulate to determine which track changes are required
    for(auto [time,u,v]:requirements){
        if(adj[u][current[u]]!=v){
            commands.pb(u,time);
            ++current[u]%=2;
        }
    }
    cout << si(commands) << endl;
    for(auto [u,t]:commands) cout << u << " " << t << endl;
	
	return 0;
}

