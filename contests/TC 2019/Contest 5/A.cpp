
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define forsn(i,s,n) for(int i = (int)s; i < (int) n; i++)
#define forn(i,n) forsn(i,0,n)
#define si(a) ((int)(a).size())

using ll = long long;

int main(){
    fastio;

    ll n,k; cin >> n >> k;
    if(k+1 > 2*n/k) return cout << "-1\n", 0; 
    ll res = -1, s = k*(k+1)/2;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            ll j = n / i;
            if(j >= s) res = max(res,i);
            if(i >= s) res = max(res,j);
        }
    }
    if(res == -1) return cout << "-1\n", 0; 
    ll d = n/res - s;
    forsn(i,1,k+1) cout << (i == k ? (k+d)*res : i*res) << " \n"[i == k];
    return 0; 
}
