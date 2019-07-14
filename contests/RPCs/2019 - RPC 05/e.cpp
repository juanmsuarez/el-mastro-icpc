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

const int N = 5e5, M = 60;
vi adj[N];
int c[N];
double memo[N][M];

double dp(int u, int left) {
    if (left == 0) return 0;

    double &res = memo[u][left];
    if (res != -1) return res;
    res = c[u];

    for (int v : adj[u])
        res = max(res, max(dp(v, left), c[u]+0.5*dp(v, left-1)));

    //cerr << u << " " << left << " " << res << endl;
    return res;
}

int main() {
	fastio;
	
    int n, m; cin >> n >> m;
    forn(i, n) cin >> c[i];
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    fill(memo[0], memo[N], -1);
    cout << fixed << setprecision(6) << dp(0, M-1) << endl;
	
	return 0;
}
