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

const ll INF = 1e9+10;

vector<ll> pops;
ll c,t;

ll test(ll mid){
    ll cant=1,acc=0;
    for(ll p:pops){
        ll act = (acc+p+t-1)/t;
        if(act>mid){
            cant++;
            acc=p;
        }
        else acc+=p;
    }
    return cant;
}

int main() {
	fastio;
	
    int n;
    cin >> n >> c >> t;
    pops = vector<ll>(n);
    ll big=0;
    for(ll& a:pops){
        cin >> a;
        big=max(big,a);
    }

    ll lo=(big+t-1)/t,hi=INF;
    if(test(lo)<=c)cout << lo << endl;
    else{
        while(hi-lo>1){
            ll mid = (lo+hi)/2;
            ll cant = test(mid);
            if(cant>c)lo=mid;
            else hi=mid;
        }
        cout << hi << endl;
    }

    

	
	return 0;
}

