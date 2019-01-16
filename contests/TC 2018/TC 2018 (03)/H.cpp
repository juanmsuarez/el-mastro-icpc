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

const int MAXN = 2e5+10;

pii cars[MAXN];
ll gas[MAXN];

int main() {
    fastio;

    int n,k;
    ll s,t;
    cin >> n >> k >> s >> t;

    forn(i,n){
        cin >> cars[i].first >> cars[i].second;
    }
    forn(i,k)cin >> gas[i];
    gas[k]=s;
    sort(gas,gas+k+1);
    
    ll lo=0,hi=1e9+10,mid;
    while(lo+1<hi){
        mid = (lo+hi+1)/2;
        ll pos=0,time=0;
        for(int i=0;i<k+1&&time<=t;i++){
            ll dx =gas[i]-pos;
            if(mid>=dx*2)time+=dx;
            else if(mid>=dx)time+=3*dx-mid;
            else time=t+1;
            pos = gas[i];
        }
        if(time<=t)hi=mid;
        else lo=mid;
    }
    ll mingas = hi;

    int res =-1;
    forn(i,n){
        if(cars[i].second>=mingas && (res==-1 || cars[i].first<res))
            res=cars[i].first;
    }
    cout << res <<endl;

    return 0;
}
