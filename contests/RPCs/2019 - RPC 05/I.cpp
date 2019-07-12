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


int main() {
	fastio;

    string s; cin >> s;
	
    hashing h1, h2;
    h1.randomize(), h2.randomize();
    h1.process(s), h2.process(s);

    int n = si(s), ans = 0, start = 0;
    while (2*start < n) {
        int k = 1; 
        auto match = [&](int l, int r) {
            return h1.hash(l, r) == h1.hash(n-r, n-l)
                && h2.hash(l, r) == h2.hash(n-r, n-l);
        };
        while (!match(start, start+k)) k++;

        start += k;

        if (2*start <= n) ans += 2;
        else ans++;
    }

    cout << ans << endl;
	
	return 0;
}
