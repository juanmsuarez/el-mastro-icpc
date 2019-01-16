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
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

mt19937 rng;
struct hashing {
    int mod, mul;

    bool prime(int n) { 
        for (int d = 2; d*d <= n; d++) if (n%d == 0) return false;
        return true;
    }

    void setValues(int mod, int mul) {
        this->mod = mod;
        this->mul = mul;
    }

    void randomize() {
        rng.seed(time(0));
        mod = uniform_int_distribution<>(0, (int) 5e8)(rng) + 1e9;
        while (!prime(mod)) mod++;
        mul = uniform_int_distribution<>(2,mod-2)(rng);
    }

    vi h, pot;
    void process(const string &s) {
        h.resize(si(s)+1);
        pot.resize(si(s)+1);
        h[0] = 0; forn(i,si(s)) h[i+1] = (((ll)h[i] * mul) + s[i]) % mod;
        pot[0] = 1; forn(i,si(s)) pot[i+1] = (ll) pot[i] * mul % mod;
    }

    int hash(int i, int j) {
        int res = h[j] - (ll) h[i] * pot[j-i] % mod;
        if (res < 0) res += mod;
        return res;
    }

    int hash(const string &s) {
        int res = 0;
        for (char c : s) res = (res * (ll) mul + c) % mod;
        return res;
    }

};

hashing h1,h2;
