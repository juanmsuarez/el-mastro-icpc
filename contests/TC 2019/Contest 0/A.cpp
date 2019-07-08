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
#define forsn(i,s,n) for(ll i=ll(s);i<ll(n);i++)
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
using ll = __int128_t;

ll mul(ll a, ll b,ll p){ return ll(ll(a)*b % p); }
ll pot(ll b, ll e,ll p){ // O(log e)
	if(!e) return 1;
	ll q = pot(b, e/2,p); q = mul(q, q,p);
	return (e & 1 ? mul(b, q,p) : q);
}
ll inv(ll x,ll p){//O(log x)
	return pot(x, p-2,p);
}


int main() {
	fastio;

    int t;
    cin >> t;
    while(t--){
        long long int n,p;
        cin >> n >>p;

        if(n>=p)cout<<0<<endl;
        else{
            ll dif=1;
            forsn(i,n+1,p){
                dif= mul(dif,i,p);
            }
            cout << (long long int)(mul(p-1,inv(dif,p),p)) << endl;
        }
    }
	
	
	return 0;
}

