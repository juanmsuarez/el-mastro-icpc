#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
#define pb emplace_back
#define si(a) int(a.size())
using vi = vector<int>;
using ll = long long int;

const ll M = 1e9+7;

ll add(ll a, ll b) { return (a + b < M ? a + b : a + b - M); }
ll sub(ll a, ll b) { return (a - b >= 0 ? a - b : a - b + M); }
ll mul(ll a, ll b) { return a * b % M; }

ll pot(ll b, ll e) {
    if (!e) return 1;
    ll q = pot(b, e/2); q = mul(q, q);
    return (e & 1 ? mul(b, q) : q);
}

ll inv(ll x) { return pot(x, M-2); }

int main(){
    ll a, k; cin >> a >> k; a %= M;

    ll ans;
    if(a==0)ans=1;
    else if (a == 1) ans = (k+1)%M;
    else ans = mul(sub(pot(a, k+1), 1), inv(a-1));
    cout << ans << endl; // a = 1?
}
