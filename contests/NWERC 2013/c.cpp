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

const vector<string> cards = {"2", "3", "4", "5", "6", "7", "8", "9", "10", 
    "J", "Q", "K", "A"};

int cardToNum(string c) {
    if (c == "A") return 11;
    if (c == "J" || c == "Q" || c == "K") return 10;
    return stoi(c);
}

vi v;
vector<double> memo;
double dp(int pos) {
    if (pos >= si(v)) return 0;
    if (v[pos] != -1) return 1;

    double &res = memo[pos];
    if (res != -1) return res;

    res = 0;
    for (string card : cards)
        res += 1./si(cards)*dp(pos+cardToNum(card));

    return res;
}

int main() {
	fastio;
	
    int n, m; 
    while (cin >> n >> m) {
        v.clear();

        int pre = m;
        while (n--) {
            forn(_, pre-1) v.pb(-1);

            string c; cin >> c;
            int mov = cardToNum(c);
            v.pb(mov);
            pre = mov;
        }

        memo.assign(si(v), -1);
        double ans = 0;
        forn(start, 10) ans += 1./10*dp(start);

        cout << fixed << setprecision(7) << ans << endl;
    }
	
	return 0;
}
