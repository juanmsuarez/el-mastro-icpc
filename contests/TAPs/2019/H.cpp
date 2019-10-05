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
        rng.seed(chrono::steady_clock::now().time_since_epoch().count());
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

    void concat(int &h_s, int h_t, int len_t) {
        h_s = ((ll)h_s * pot[len_t] % mod + h_t) % mod;
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

    void concat(pii &h_s, pii h_t, int len_t) {
        h1.concat(h_s.fst, h_t.fst, len_t); 
        h2.concat(h_s.snd, h_t.snd, len_t);
    }
};

string alphabet;
void init_alphabet() {
    alphabet = ",._"; forn(c, 26) alphabet += 'a' + c; 
}


int main() {
	fastio;

    init_alphabet();
	
    int n; string s; cin >> n >> s;
    int r, m; cin >> r >> m;
    vector<string> ps(r); for (string &p : ps) cin >> p;

    hashing h;
    h.process(s);

    map<pii, int> ap_s;
    forn(i, n - m + 1) ap_s[h.hash(i, i + m)]++;

    int ans = 0;
    for (string &p : ps) {
        h.process(p);

        forn(i, m) {
            for (char c : alphabet) if (c != p[i] || i == 0) {
                pii h_p = h.hash(0, i);
                h.concat(h_p, h.hash(string(1, c)), 1);
                h.concat(h_p, h.hash(i + 1, m), m - i - 1);
                ans += ap_s[h_p];
            }
        }
    }

    cout << ans << endl;
	
	return 0;
}
