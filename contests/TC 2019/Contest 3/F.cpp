
#include <bits/stdc++.h>
using namespace std;


#define forsn(i,s, n) for (ll i = (ll)s; i < (ll)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define snd second
#define si(a) ((int)(a).size())
#define pb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

ull mulmod(ull a, ull b, ull m) {
    long double x; ull c; ll r;
    x = a; c = x * b / m;
    r = (ll)(a * b - c * m) % (ll)m;
    return r < 0 ? r + m : r;
}

ll expmod(ll b, ll e, ll m){
    if(!e)return 1;
    ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
    return e%2? mulmod(b,q,m) : q;

}

bool es_primo_prob(ll n,int a){
    if(n==a)return true;
    ll s = 0,d=n-1;
    while(d%2 ==0)s++,d/=2;

    ll x = expmod(a,d,n);
    if((x==1) || (x+1 == n))return true;

    forn(i,s-1){
        x=mulmod(x,x,n);
        if(x== 1)return false;
        if(x+1==n)return true;
    }
    return false;
    
}


bool rabin(ll n){
    if(n==1)return false;
    const int ar[] = {2,3,5,7,11,13,17,19,23};
    forn(j,9){
        if(!es_primo_prob(n,ar[j]))return false;
    }
    return true;
}

int main() {


    int t;
    cin >> t;
    while(t--){

        ll n,m;
        cin >> n >> m;

        forsn(i,n,m+1){
            if(rabin(i))cout << i << endl;
        }
        if (t != 0) cout << endl;
    }
    //upsolving

}
