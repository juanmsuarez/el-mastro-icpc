#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
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

bitset<300>vis;
vi f;
vi distCycle;

int markCycles(int u){
    if(!distCycle[u])return 0;
    if(vis[u]){
        int sizeCycle = 0;
        while(distCycle[u]){
            distCycle[u]=0;
            u=f[u];
            sizeCycle++;
        }
        return sizeCycle;
    }
    vis[u]=true;
    int sz=markCycles(f[u]); 
    vis[u]=false;
    return sz;
}

int calcDist(int u){
    if(distCycle[u]!=-1)return distCycle[u];
    return distCycle[u] = 1 + calcDist(f[u]);
}

int main() {
	fastio;
	
    int n;
    cin >> n;

    f = vi(n+1);
    distCycle = vi(n+1,-1);
    forn(i,n)cin >> f[i+1];

    ll A=1;
    forsn(i,1,n+1){
        ll sz = markCycles(i);
        if(sz)A = lcm(A,sz);
    }
    ll B = 0;
    forsn(i,1,n+1){
        B = max(B,(ll)calcDist(i));
        D(distCycle[i]);
    }

    cerr << A << " " << B << endl;
    cout << A* max(1ll,((B+A-1ll)/A)) << endl;

    
	
	return 0;
}

