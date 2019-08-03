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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int M = 100+10;
int memo[M][M];

int mex(vi &v) {
    sort(all(v));

    int m = 0;
    for (int x : v)
        if (x > m) return m;
        else if (x == m) m++;

    return m;
}

int grundy(int r, int c) {
    if (r == 0 || c == 0 || r == c) return -1;
    //cerr << r << ' ' << c << endl;

    int &ans = memo[r][c];
    if (ans != -1) return ans;

    vi v;
    forsn(k, 1, r) v.pb(grundy(r-k, c));
    forsn(k, 1, c) v.pb(grundy(r, c-k));
    forsn(k, 1, min(r,c)) v.pb(grundy(r-k,c-k));

    //cerr << r << ' ' << c << ' ' << ans << endl;

    return ans = mex(v);
}

int main() {
	fastio;

    fill(memo[0], memo[M], -1);

    /*
    forn(i, 10) {
        forn(j, 10) cerr << grundy(i, j) << '\t';
        cerr << endl;
    }
    */
	
    int n, ans = 0; cin >> n;
    bool win = false;
    forn(_, n) {
        int r, c; cin >> r >> c;
        if (r == c) win = true;
        ans = ans ^ grundy(r,c);
    }        
    cout << (!win && (ans == 0) ? 'N' : 'Y') << endl;
	
	return 0;
}
