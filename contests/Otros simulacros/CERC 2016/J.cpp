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

#define INF 1e18

int main() {
	fastio;
    
    map<pii,int> trips,oneway,roundtrip;
    set<pii> vis;

    int n,d; cin >> n >> d;
    int p; cin >> p;
    forn(i,d-1){
        int x; cin >> x;
        trips[{p,x}]++;
    }
    
    int m; cin >> m;
    forn(i,m){
        int a,b,d; char c; cin >> a >> b >> c >> d;
        int v = d;
        if(c == 'O'){
            if(oneway.count({a,b})) v = oneway[{a,b}];
            oneway[{a,b}] = min(v,d);
        } else {
            if(roundtrip.count({a,b})) v = roundtrip[{a,b}];
            roundtrip[{a,b}] = min(v,d);
        }
    }
    
    ll res = 0;
    for(auto &i : trips) if(!vis.count(i.fst)){
        int a = i.snd, b = 0;
        pii o = {i.fst.snd,i.fst.fst};
        if(trips.count(o)) b = trips[o];
        int c = min(a,b);
        bool o1 = oneway.count(i), o2 = oneway.count(o);
        bool r1 = roundtrip.count(i), r2 = roundtrip.count(o);
        int v1 = INF, v2 = INF, v3 = INF;
        if()           
    

       vis.insert(o); 
    }
    cout << res << endl;
	return 0;
}
