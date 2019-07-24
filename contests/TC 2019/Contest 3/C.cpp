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

mt19937 rng;
struct basicHashing {
    int mod, mul;

    bool prime(int n) { 
        for (int d = 2; d*d <= n; d++) if (n%d == 0) return false;
        return true;
    }

    void randomize() {
        rng.seed(time(0));
        mod = uniform_int_distribution<>(0, (int) 5e8)(rng) + 1e9;
        while (!prime(mod)) mod++;
        mul = uniform_int_distribution<>(2,mod-2)(rng);
    }

    basicHashing() { randomize(); }

    vi h, pot;
    void process(const string &s) {
        h.resize(si(s)+1);
        pot.resize(si(s)+1);
        h[0] = 0; forn(i,si(s)) h[i+1] = (((ll)h[i] * mul) + s[i]) % mod;
        pot[0] = 1; forn(i,si(s)) pot[i+1] = (ll)pot[i] * mul % mod;
    }

    int hash(int i, int j) {
        int res = h[j] - (ll)h[i] * pot[j-i] % mod;
        if (res < 0) res += mod;
        return res;
    }

    int hash(const string &s) {
        int res = 0;
        for (char c : s) res = ((ll)res * mul + c) % mod;
        return res;
    }

};

struct hashing {
    basicHashing h1, h2;

    void process(const string &s) {
        h1.process(s);
        h2.process(s);
    }

    pii hash(int i, int j) {
        return {h1.hash(i, j), h2.hash(i, j)};
    }

    pii hash(const string &s) {
        return {h1.hash(s), h2.hash(s)};
    }
};

int main() {
	fastio;


	
	return 0;
}
