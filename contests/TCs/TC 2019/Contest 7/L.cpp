#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl;
#else
    #define D(a)
    #define cerr false && cerr
#endif
#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (int)(n-1); i >= (int) s;i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb emplace_back
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;

const int P = 10+10, L = 64+10;

ll tope;
ll memo[L][L][2];

ll dp(int sz, int ones, bool equal) {
    if (ones == 0) return 1;
    if (sz == 0) return 0;

    ll &res = memo[sz][ones][equal];
    if (res != -1) return res;

    bool isOne = tope & (1LL<<(sz-1));

    if (equal) {
        res = dp(sz-1, ones-isOne, equal); // dejo igual

        if (isOne) res += dp(sz-1, ones, false); // pongo 0
    }
    else 
        res = dp(sz-1, ones, equal) + dp(sz-1, ones-1, equal); // pruebo los 2

    return res;
}

vector<vi> nxt;
int k;
ll calc(ll x) {
    if (x == 0) return k == 1; // TODO
    tope = x;
    fill(memo[0][0], memo[L][0], -1);

    int sz = 64 - __builtin_clzll(x);
    ll res = 0;
    for (int n : nxt[k-1]) res += dp(sz, n, true);

    return res;
}

int main(){
    fastio;

    nxt.resize(P);

    forsn(n, 1, L) {
        int temp = n, pasos = 0;
        while (temp > 1) {
            temp = __builtin_popcount(temp);
            pasos++;
        } 
        nxt[pasos].pb(n);
    }

    ll lo, hi;
    while (cin >> lo >> hi >> k && lo != 0) {
        if (k == 0) cout << (1 >= lo && 1 <= hi) << endl;
        else cout << calc(hi) - calc(lo-1) << endl;
    }

int mastroesmimaestro;

    return 0; 
}
