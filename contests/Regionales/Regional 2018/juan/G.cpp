#include <bits/stdc++.h>
using namespace std;

//#define cerr false && cerr

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define mt make_tuple
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<pii> vii;

const int N = 1e3+10, M = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int add(int a, int b) { return a+b >= M ? a+b-M : a+b; }
int sub(int a, int b) { return a-b < 0 ? a-b+M : a-b; }
int mul(int a, int b) { return int((ll)a*b%M); }
int pot(int b, int e){ // O(log e)
	if (!e) return 1;
	int q = pot(b, e/2); q = mul(q, q);
	return (e % 2 ? mul(b, q) : q);
}
int inv(int x) { return pot(x, M-2); }

int fact[N];
pii ps[N];

struct proy {
    pii ang; int mag, id; bool orig;

    proy(pii _ang, int _mag, int _id, bool _orig) : 
        ang(_ang), mag(_mag), id(_id), orig(_orig) {}

    bool operator < (const proy &o) const {
        return mt(ang, mag, ps[id], id, orig) < 
            mt(o.ang, o.mag, ps[o.id], o.id, o.orig);
    }
};

int main() {
	fastio;

    fact[0] = 1; forsn(i, 1, N) fact[i] = mul(fact[i-1], i);
	
    int n; cin >> n;    
    forn(i, n) cin >> ps[i].fst >> ps[i].snd;

    vector<proy> proys;
    forn(i, n) {
        pii a = ps[i];
        for (pii b : ps) {
            int y = b.snd - a.snd, x = a.fst - b.fst;

            if (a == mp(0, 0) || b == mp(0, 0)) continue;
            if (x < 0 && y < 0) x *= -1, y *= -1;
            if (x <= 0 || y <= 0) continue;

            int g = gcd(x,y); x /= g, y /= g;

            proys.pb(mp(y, x), a.fst*y + a.snd*x, i, false);
        }

        proys.pb(mp(a.snd, a.fst), a.fst*a.snd + a.snd*a.fst, i, true);
    }

    sort(all(proys));

    vector<pii> lines;
    int i = 0, m = si(proys), all_rep_fact = 1;
    while (i < m) {
        pii line_ang = proys[i].ang;
        int line_single_rep_fact = 1, line_fact = 1;
        bool hasproy = false;

        while (i < m && proys[i].ang == line_ang) {
            int group_mag = proys[i].mag, group_cant = 0;

            while (i < m && mt(proys[i].ang, proys[i].mag) == mt(line_ang, group_mag)) {
                pii point = ps[proys[i].id];
                int point_rep_proy = 0, point_rep_orig = 0;

                while (i < m && mt(proys[i].ang, proys[i].mag, ps[proys[i].id]) 
                        == mt(line_ang, group_mag, point)) {
                    int point_id = proys[i].id;

                    while (i < m && mt(proys[i].ang, proys[i].mag, proys[i].id) 
                            == mt(line_ang, group_mag, point_id)) {
                        bool point_orig = proys[i].orig;

                        if (point_orig) point_rep_orig++;
                        else { 
                            hasproy = true; 
                            point_rep_proy++; 
                        }

                        while (i < m && mt(proys[i].ang, proys[i].mag, proys[i].id, proys[i].orig) 
                                == mt(line_ang, group_mag, point_id, point_orig)) {
                            i++;
                        }
                    }
                }

                line_single_rep_fact = mul(line_single_rep_fact, fact[point_rep_proy]);
                all_rep_fact = mul(all_rep_fact, fact[point_rep_orig]);
                group_cant += point_rep_proy;
            }

            line_fact = mul(line_fact, fact[group_cant]);
        }

        if (hasproy) lines.pb(line_fact, line_single_rep_fact);
    }

    int ans = all_rep_fact;
    for (pii line : lines) {
        int fact, single_rep_fact; tie(fact, single_rep_fact) = line;
        ans = add(ans, mul(fact, mul(all_rep_fact, inv(single_rep_fact))));
        ans = sub(ans, all_rep_fact);
    }

    cout << ans << endl;
	
	return 0;
}
