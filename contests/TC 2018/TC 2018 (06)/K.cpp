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
    #define D(a) cerr << #a << "=" << a << endl
#else
    #define D(a)
    #define cerr  false && cerr
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;
typedef tuple<int,int,int> ti;

mt19937 rng;
#define hash __nico_hash
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

    int hash(const string &s, int i, int j) {
        int res = 0;
        forsn(k, i, j) res = (res * (ll) mul + s[k]) % mod;
        return res;
    }

};


hashing h[2];

const int MAXL = 1000+5, INF = 1e9;

int main() {
    fastio;

    string s; int m;
    cin >> s >> m;

    forn(i, 2) {
        h[i].randomize();
        h[i].process(s);
    }

    set<ti> inc, dec;

    forn(i, si(s)) 
        forsn(j, i+1, min(si(s)+1, j+MAXL)) {
            int h0 = h[0].hash(i, j), h1 = h[1].hash(i, j);
            //cerr << h0 << ' ' << h1 << ' ' << i << ' ' << j << endl;
            inc.insert({h0, h1, j});
            dec.insert({h0, h1, -i});
        }

    //cerr << endl << "queries" << endl;

    int ans = 0;
    forn(_, m) {
        string w;
        cin >> w;

        //cerr << "mirando str " << w << endl;

        bool found = false;

        forn(i, si(w)) {
            int lh0 = h[0].hash(w, 0, i), lh1 = h[1].hash(w, 0, i), 
                rh0 = h[0].hash(w, i, si(w)), rh1 = h[1].hash(w, i, si(w)),
                flh0, flh1, lind, frh0, frh1, rind;

            //cerr << "hasheo a " << endl;
            //cerr << lh0 << ' ' << lh1 << endl << rh0 << ' ' << rh1 << endl;

            auto itinc = inc.lower_bound({lh0, lh1, 0}),
                 itdec = dec.lower_bound({rh0, rh1, -INF});

            if (itinc == inc.end() || itdec == dec.end()) continue;

            tie(flh0, flh1, lind) = *itinc;
            tie(frh0, frh1, rind) = *itdec;
            
            if (flh0 != lh0 || flh1 != lh1 || frh0 != rh0 || frh1 != rh1) continue;

            /*
            cerr << "para pos " << i << " encontro " << lind << ' ' << -rind << endl;
            cerr << lh0 << ' ' << lh1 << endl;
            cerr << rh0 << ' ' << rh1 << endl;
            */

            if (lind <= -rind) {
                found = true;
                break;
            }
        }

        //cerr << found << endl;
        //cerr << endl;
        ans += found;
    }
    cout << ans << endl;

    return 0;
}
