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

const int MAXN = 1e3+10;
const ll INF = 1e18;
ll x[MAXN], w[MAXN], dp[MAXN][MAXN], cost[MAXN][MAXN];

void calc(int i, int jl, int jr, int optl, int optr) {
    int j = (jl+jr)/2, opt;

    dp[i][j] = INF;
    forsn(k, optl, min(optr, j-1)+1) {
        ll val = dp[i-1][k] + cost[k][j-1];
        if (val < dp[i][j]) {
            dp[i][j] = val;
            opt = k;
        }
    }

    if (jl <= j-1) calc(i, jl, j-1, optl, opt);
    if (j+1 <= jr) calc(i, j+1, jr, opt, optr);
}

int main() {
	fastio;
	
    int n, k;
    while (cin >> n >> k) {
        dforn(i, n) cin >> x[i] >> w[i];

        forn(i, n) forsn(j, i+1, n) cost[i][j] = cost[i][j-1] + (x[i]-x[j])*w[j];

        forsn(j, 1, n+1) dp[0][j] = INF; dp[0][0] = 0;
        forsn(i, 1, k+1) calc(i, i, n, i == 1 ? 0 : 1, n-1);
        
        cout << dp[k][n] << endl;
    }       
	
	return 0;
}
