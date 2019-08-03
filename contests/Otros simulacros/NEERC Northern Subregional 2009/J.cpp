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

const ll M = LLONG_MAX;

int main() {
	fastio;

    freopen("jealous.in","r",stdin);
    freopen("jealous.out","w",stdout);
	
    ll a,b,p,q; cin >> a >> b >> p >> q;
    ll v[] = {b,a-1}, r = 0;
    forn(_,2){
        ll l = v[_], x = 1; 
        forsn(i,1,65){
            if(x < M/p && x*p <= l) x *= p;
            else break;
            ll y = x;
            forn(j,i){
                ll mnp = 0, mnq = 0, mnpq = 0;
                if(y < M/p) mnp = l/(y*p);
                if(y < M/q) mnq = l/(y*q);
                if(y < M/p && y*p < M/q) mnpq = l/(y*p*q);
                r += (l/y-mnp-mnq+mnpq)*(_?-1:1);
                if(y < M/q && y*q <= l) y *= q;
                else break;  
            }
        }
    }
    cout << r << endl;
	return 0;
}
