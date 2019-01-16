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
#define snd second
#define fst first
#define endl '\n'
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<pii> vii;


const int N = 1e6+10, M = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int add(int a, int b) { return a+b >= M ? a+b-M : a+b; }
int sub(int a, int b) { return a-b < 0 ? a-b+M : a-b; }
int mul(int a, int b) { return (ll)a*b%M; }
int pot(int b, int e){ // O(log e)
	if (!e) return 1;
	int q = pot(b, e/2); q = mul(q, q);
	return (e % 2 ? mul(b, q) : q);
}
int inv(int x) { return pot(x, M-2); }

int fact[N];

void mul_map(auto &m, auto &e, int x) {
    m[e] = mul(m.count(e) ? m[e] : 1, x);
}

int main() {
	fastio;

    fact[0] = 1; forsn(i, 1, N) fact[i] = mul(fact[i-1], i);
	
    int n; cin >> n;    
    map<pii, int> cant;
    forn(i, n) {
        int r, b; cin >> r >> b;
        cant[{r,b}]++;
    }

    int multrep = 1;
    map<pair<pii, int>, int> midpoints, midpoints_rep;
    for (auto p1 : cant) {
        pii a; int ca; tie(a, ca) = p1;

        set<pair<pii, int>> s;
        for (auto p2 : cant) {
            pii b; int cb; tie(b, cb) = p2;

            int y = b.snd - a.snd, x = a.fst - b.fst;

            if (a == mp(0, 0) || b == mp(0, 0)) continue;
            if (x < 0 && y < 0) x *= -1, y *= -1;
            if (x <= 0 || y <= 0) continue;

            int g = gcd(x,y); x /= g, y /= g;
            s.emplace(mp(y, x), a.fst*y + a.snd*x);
        }

        for (auto p : s) {
            if (p == mp(mp(1,2),4))
                cerr << ca << endl;
            midpoints[p] += ca;
            mul_map(midpoints_rep, p, fact[ca]);
        }

        multrep = mul(multrep, fact[ca]);
    }

    map<pii, int> lines, lines_rep;
    for (auto p : midpoints) {
        pii ang = p.fst.fst; int c = p.snd;

        mul_map(lines, ang, fact[c]);
        mul_map(lines_rep, ang, midpoints_rep[p.fst]);
    }

    int ans = multrep;
    cerr << multrep << endl;
    for (auto p : lines) {
        cerr << "line " << p.snd << ' ' << lines_rep[p.fst] << endl;
        int new_line_rep = mul(multrep, inv(lines_rep[p.fst]));
        ans = add(ans, sub(mul(p.snd, new_line_rep), multrep));
    }

    cout << ans << endl;
	
	return 0;
}
