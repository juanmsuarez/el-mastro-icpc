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

const int N = 10, T = 2e3, M = (1<<N), INF = 1e9;
int n, last[N][T], win[N][T], memo[T][M];
bool seen[T][M];

typedef tuple<int,int,int,int> event;

int dp(int t, int mask) {
    if (t == T) return mask == (1<<n)-1 ? 0 : -INF;

    int &res = memo[t][mask];
    if (seen[t][mask]) return res;
    res = -INF; seen[t][mask] = true;

    res = max(res, dp(t+1, mask));
    forn(show, n)
        if (last[show][t]) 
            res = max(res, dp(last[show][t], (mask | (1<<show))) + win[show][t]);

    return res;
}

int main() {
	fastio;
	
    cin >> n;
    vector<event> es; vi ts;
    forn(show, n) {
        int m; cin >> m;
        forn(_, m) {
            int i, f, o; cin >> i >> f >> o;
            ts.pb(i); ts.pb(f);
            es.pb(show,i,f,o);
            //last[show][i] = f; win[show][i] = o;
        }
    }    
    sort(all(ts)); ts.erase(unique(all(ts)), ts.end());
    for (event &e : es) {
        int show, i, f, o; tie(show, i, f, o) = e;
        i = lower_bound(all(ts), i) - ts.begin();
        f = lower_bound(all(ts), f) - ts.begin();

        last[show][i] = f;
        win[show][i] = o;
    }

    fill(memo[0], memo[T], -1);
    int res = dp(0, 0);
    cout << (res <= 0 ? -1 : res)  << endl;
	
	return 0;
}
