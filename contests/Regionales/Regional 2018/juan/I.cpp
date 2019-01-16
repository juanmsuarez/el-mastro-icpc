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
typedef vector<pii> vii;

const int N = 1e5, INF = 1e9;
vi ch[N];
int memo[N][3];

enum tipo { leaf, out, mid };

int dp(int u, tipo t) {
    int &res = memo[u][t];
    if (res != -1) return res;

    int best[3][2]; // leafs, mid
    forn(i, 3) forn(j, 2) best[i][j] = -INF;
    best[0][0] = 0;

    for (int v : ch[u]) {
        dforn(i, 3) dforn(j, 2) {
            best[i][j] += dp(v, out);
            if (i > 0) best[i][j] = max(best[i][j], best[i-1][j] + dp(v, leaf));
            if (j > 0) best[i][j] = max(best[i][j], best[i][j-1] + dp(v, mid));
        }
    }

    if (t == leaf) return res = best[0][0];
    else if (t == out) return res = max(best[0][0], best[2][1] + 1);
    else return res = best[2][0]; // mid
}

int main() {
	fastio;

    fill(memo[0], memo[N], -1);
	    
    int n; cin >> n;
    forsn(u, 1, n) {
        int p; cin >> p; p--;
        ch[p].pb(u);
    }    

    cout << dp(0, leaf) << endl;
	
	return 0;
}
