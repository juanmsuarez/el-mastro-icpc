#include <iostream>
#include <vector>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define eb emplace_back
#define pb push_back
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

const int MAXN = 5e5+10, INF = 1<<30;
tint pos[MAXN];
int n;
tint l;
tint a, b, t, r;

vi adj[MAXN];

struct time{
    int ind;
    tint da,db;
    time * next = nullptr;
    time(int _ind,tint _da,tint _db):ind(_ind),da(_da),db(_db){}
    time(int _ind,tint d):time(_ind, min(a*t,d)+max(d-a*t-b*r,0ll),  min(b*r,max(0ll,d-a*t))){}
    
    void minval(time * nxt,tint dist){
        time act(ind, dist);
        act.da += nxt->da;
        act.db += nxt->db;
        if(b*(da-act.da)>=a*(act.db-db)){
            da=act.da;
            db=act.db;
            next= nxt;
        }
    }

    void print(int cant){
        if(!next){
            cout << cant+1 << "\n";
            cout << ind;
        }
        else{
            next->print(cant+1);
            cout << " " << ind;
        } 
        if(!cant)cout << "\n";
    }
};

time* memo[MAXN];

time * dp(int p) {
    time * &res = memo[p];
    if (res) return res;
    res = new time(p,l-pos[p]);
    for (int nxt : adj[p]){
        res->minval(dp(nxt),pos[nxt]-pos[p]);
    }
    return res;
}

int main() {
    fastio;

    cin >> l >> a >> b >> t >> r;

    tint dist = a*t+r*b;

    cin >> n; 
    forn(i, n) cin >> pos[i];  
    fill(memo, memo+MAXN, nullptr);
    
    int lo = 0;
    forn(i, n) {
        while (lo+1 < n && pos[lo+1] <= pos[i]+dist) lo++;
        
        if (lo != i)adj[i].pb(lo);
        if(lo+1<n)adj[i].pb(lo+1);
    }
    if(n)dp(0)->print(0);
    else cout << 0 << endl;

    return 0;
}
