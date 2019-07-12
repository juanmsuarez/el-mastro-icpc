#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define dprint(v) cerr << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
typedef long long ll;

ll gcd(ll a, ll b){return b?__gcd(a,b):a;}

typedef unsigned long long ull;
ull mulmod(ull a, ull b, ull m){ // 0 <= a, b < m
   long double x; ull c; ll r;
   x = a; c = x * b / m;
   r = (ll)(a * b - c * m) % (ll)m;
   return r < 0 ? r + m : r;
}

ll expmod(ll b, ll e, ll m){ // O(log(b))
	ll ans = 1;
	while(e){
        if(e&1)ans = mulmod(ans, b, m);
        b = mulmod(b, b, m); e >>= 1;
	}
	return ans;
}

bool es_primo_prob (ll n, int a)
{
	if (n == a) return true;
	ll s = 0,d = n-1;
	while (d % 2 == 0) s++,d/=2;
	
	ll x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;
	
	forn (i, s-1){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}
		
bool rabin (ll n){ //devuelve true si n es primo O(n^0.25)
	if (n == 1)	return false;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	forn (j,9)
		if (!es_primo_prob(n,ar[j]))
			return false;
	return true;
}

ll rho(ll n){   
    if(!(n&1))return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand()%n + 1;
    while(d == 1){
        x = (mulmod(x,x, n)+c)%n;
        y = (mulmod(y,y, n)+c)%n;
        y = (mulmod(y,y, n)+c)%n;
        if(x >= y)d = gcd(x-y, n);
        else d = gcd(y-x, n);
    }
    return d == n ? rho(n) : d;
}
void fact(ll n, map<ll,int>& f){ //O (lg n)^3
	if(n == 1)return;
	if(rabin(n)){ f[n]++; return; }
	ll q = rho(n); fact(q, f); fact(n/q, f);
}


int main(){
	ll n;
	while(1){
		n=abs((ll)rand()*rand()*rand()%(ll(1e18))+50);
		dprint(n);
		if(!rabin(n)){
			//~ dprint(n);
			ll ans = rho (n);
			assert(!(n%ans) && ans>0);
		}
	}
	n = 2063512844981574047LL;
	while(cin >> n){
		dprint(n);
		if(rabin (n))
			cout << n << " es primo.\n";
		else{
			ll ans = rho (n);
			if (ans > n / ans) ans = n / ans;
			printf ("%lld = %lld * %lld\n", n, ans, n / ans);
		}
    }
    return 0;
}
